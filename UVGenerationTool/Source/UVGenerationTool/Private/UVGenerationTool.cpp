// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UVGenerationTool.h"

#include "RawMesh.h"
#include "Engine/StaticMesh.h"
#include "ContentBrowserModule.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

#include "MyXatlas.h"

#define LOCTEXT_NAMESPACE "FUVGenerationToolModule"

void FUVGenerationToolModule::StartupModule()
{
	SetupContentBrowserContextMenuExtender();
}

void FUVGenerationToolModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

void FUVGenerationToolModule::SetupContentBrowserContextMenuExtender()
{
	if (!IsRunningCommandlet())
	{
		FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
		TArray< FContentBrowserMenuExtender_SelectedAssets >& CBMenuExtenderDelegates = ContentBrowserModule.GetAllAssetViewContextMenuExtenders();
		CBMenuExtenderDelegates.Add(FContentBrowserMenuExtender_SelectedAssets::CreateStatic(&FUVGenerationToolModule::OnExtendContentBrowserAssetSelectionMenu));
	}
}

TSharedRef<FExtender>  FUVGenerationToolModule::OnExtendContentBrowserAssetSelectionMenu(const TArray<FAssetData>& SelectedAssets)
{
	TSharedRef<FExtender> Extender = MakeShared<FExtender>();
	TArray<UStaticMesh*> StaticMeshes;
	//筛选选中资源的类型，当前筛选的是UStaticMesh类型
	for (const FAssetData& Asset : SelectedAssets)
	{
		if (Asset.AssetClass == UStaticMesh::StaticClass()->GetFName())
		{
			if (UStaticMesh * SelectedStaticMesh = Cast<UStaticMesh>(Asset.GetAsset()))
			{
				StaticMeshes.Add(SelectedStaticMesh);
			}
		}
	}
	//如果选中了一个以上的UStaticMesh资源，则为他创建一个右键菜单
	if (StaticMeshes.Num() > 0)
	{
		Extender->AddMenuExtension("GetAssetActions", EExtensionHook::First, nullptr, FMenuExtensionDelegate::CreateLambda(
			[StaticMeshes](FMenuBuilder& MenuBuilder)
		{
			MenuBuilder.AddMenuEntry(
				LOCTEXT("Generate UV", "Generate UV"),//要显示的菜单标签名
				LOCTEXT("Tooltip", "Tool tip"),//鼠标悬停在该菜单上时的提示
				FSlateIcon(),//使用的图标
				FUIAction(FExecuteAction::CreateStatic(&FUVGenerationToolModule::GeneratUVExec, StaticMeshes), FCanExecuteAction()));//菜单执行的操作
		}));
	}
	return Extender;
}

void FUVGenerationToolModule::GeneratUVExec(TArray<UStaticMesh*> StaticMeshes)
{
	for (int32 MeshNum = 0; MeshNum < StaticMeshes.Num(); ++MeshNum)
	{
		std::vector<float> Xatlas_v;
		std::vector<float> Xatlas_vn;
		std::vector<int> Xatlas_index;
		std::vector<MyXatlas::outVertex> NewVertex;//用来保存计算结果

		FRawMesh InNewMesh;
		StaticMeshes[MeshNum]->GetSourceModel(0).LoadRawMesh(InNewMesh);

		/*读取StaticMesh的数据*/
		int OldVertexPositionsNum = InNewMesh.VertexPositions.Num();
		Xatlas_v.resize(OldVertexPositionsNum * 3);
		for (int i = 0; i < OldVertexPositionsNum;i++)
		{
			Xatlas_v[i * 3] = InNewMesh.VertexPositions[i].X;
			Xatlas_v[i * 3 + 1] = InNewMesh.VertexPositions[i].Y;
			Xatlas_v[i * 3 + 2] = InNewMesh.VertexPositions[i].Z;
		}
		int OldWedgeTangentNum = InNewMesh.WedgeTangentZ.Num();
		Xatlas_vn.resize(OldWedgeTangentNum * 3);
		for (int i = 0; i < OldWedgeTangentNum;i++)
		{
			Xatlas_vn[i * 3] = InNewMesh.WedgeTangentZ[i].X;
			Xatlas_vn[i * 3 + 1] = InNewMesh.WedgeTangentZ[i].X;
			Xatlas_vn[i * 3 + 2] = InNewMesh.WedgeTangentZ[i].X;
		}
		int OldWedgeIndicesNum = InNewMesh.WedgeIndices.Num();
		Xatlas_index.resize(OldWedgeIndicesNum);
		for (int i = 0; i < OldWedgeIndicesNum;i++)
			Xatlas_index[i] = InNewMesh.WedgeIndices[i] + 1;//Xatlas中的索引是从1开始的

		/*生成UV*/
		NewVertex = MyXatlas::GenerateUV(Xatlas_v, Xatlas_vn, Xatlas_index);

		int NewWedgeIndicesNum = NewVertex[0].Index.size();
		if (NewVertex.size() == 0)
		{
			UE_LOG(LogClass, Log, TEXT("outV.size() == 0"));//生成UV失败
			return;
		}

		//加载新的顶点位置
		InNewMesh.VertexPositions.Empty();
		InNewMesh.VertexPositions.AddZeroed(NewVertex.size());
		for (int32 i = 0; i < InNewMesh.VertexPositions.Num(); ++i)
		{
			InNewMesh.VertexPositions[i] = FVector(NewVertex[i].outP.x, NewVertex[i].outP.y, NewVertex[i].outP.z);
		}

		//加载新的顶点索引
		InNewMesh.WedgeIndices.Empty();
		InNewMesh.WedgeIndices.AddZeroed(NewWedgeIndicesNum);
		for (int i = 0;i < InNewMesh.WedgeIndices.Num();i++)
		{
			InNewMesh.WedgeIndices[i] = NewVertex[0].Index[i] - 1;
		}

		//材质索引 如果新的面数等于原面数则不需重置
		if (NewWedgeIndicesNum / 3 != InNewMesh.FaceMaterialIndices.Num())
		{
			InNewMesh.FaceMaterialIndices.Empty();
			InNewMesh.FaceMaterialIndices.AddZeroed(NewWedgeIndicesNum / 3);
			InNewMesh.FaceSmoothingMasks.Empty();
			InNewMesh.FaceSmoothingMasks.AddZeroed(NewWedgeIndicesNum / 3);
			for (int32 i = 0; i < 30; ++i)
			{
				InNewMesh.FaceMaterialIndices[i] = 0;
				InNewMesh.FaceSmoothingMasks[i] = 0;
			}
		}

		//加载新的顶点纹理和法线
		InNewMesh.WedgeTexCoords[0].Empty();
		InNewMesh.WedgeTexCoords[0].AddZeroed(NewWedgeIndicesNum);
		InNewMesh.WedgeTangentX.Empty();
		InNewMesh.WedgeTangentX.AddZeroed(NewWedgeIndicesNum);
		InNewMesh.WedgeTangentY.Empty();
		InNewMesh.WedgeTangentY.AddZeroed(NewWedgeIndicesNum);
		InNewMesh.WedgeTangentZ.Empty();
		InNewMesh.WedgeTangentZ.AddZeroed(NewWedgeIndicesNum);
		for (int32 i = 0; i < NewWedgeIndicesNum; ++i)
		{
			InNewMesh.WedgeTexCoords[0][i] = FVector2D(
				NewVertex[InNewMesh.WedgeIndices[i]].outT.u,
				NewVertex[InNewMesh.WedgeIndices[i]].outT.v);//传入UV信息

			InNewMesh.WedgeTangentX[i] = FVector(0, 0, 0);
			InNewMesh.WedgeTangentY[i] = FVector(0, 0, 0);
			InNewMesh.WedgeTangentZ[i] = FVector(0, 0, 0);//传入法线信息
		}

		StaticMeshes[MeshNum]->GetSourceModel(0).SaveRawMesh(InNewMesh);
		StaticMeshes[MeshNum]->MarkPackageDirty();
		StaticMeshes[MeshNum]->Build();
		StaticMeshes[MeshNum]->PostEditChange();
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUVGenerationToolModule, UVGenerationTool)