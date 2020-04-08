// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class Xatlas : ModuleRules
{
    public Xatlas(ReadOnlyTargetRules Target) : base(Target)
    {
        Type = ModuleType.External;

        PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "Include") });
        PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "Include/thirdparty") });
        PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "Include/thirdparty/bgfx/include") });
        PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "Include/thirdparty/bx/include") });
        PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "Include/thirdparty/imgui") });
        PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "Include/thirdparty/eigen") });
        PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "Include/thirdparty/embree3") });
        PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "Include/thirdparty/enkiTS") });
        PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "Include/thirdparty/glfw/include") });
        PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "Include/thirdparty/libigl/include") });
        PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "Include/thirdparty/mimalloc/include") });
        PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "Include/thirdparty/oidn/include") });
        PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "Include/thirdparty/OpenFBX") });
        PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "Include/thirdparty/OpenNL") });
        PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "Include/thirdparty/bx/include/compat/msvc") });

        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Lib/xatlas.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Lib/bgfx.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Lib/bimg.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Lib/bx.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Lib/cgltf.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Lib/enkiTS.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Lib/glfw.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Lib/imgui.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Lib/mimalloc.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Lib/nativefiledialog.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Lib/objzero.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Lib/OpenFBX.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Lib/OpenNL.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Lib/stb_image.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Lib/stb_image_resize.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Lib/stb_image_write.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Lib/tiny_obj_loader.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Lib/viewer.lib"));

        // Add the import library
        //PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "x64", "Release", "ExampleLibrary.lib"));

        // Delay-load the DLL, so we can load it from the right place first
        //PublicDelayLoadDLLs.Add("ExampleLibrary.dll");

        // Ensure that the DLL is staged along with the executable
        //RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/PLUGIN_NAMELibrary/Win64/ExampleLibrary.dll");
    }
}
