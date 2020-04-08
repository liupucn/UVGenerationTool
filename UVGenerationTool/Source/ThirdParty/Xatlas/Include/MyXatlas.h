/*
xatlas
https://github.com/jpcy/xatlas
Copyright (c) 2018 Jonathan Young
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

#include <stb_image_write.h>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4201)
#endif
#include <tiny_obj_loader.h>
#ifdef _MSC_VER
#pragma warning(pop)
#endif

#include "..//../xatlas.h"

#ifdef _MSC_VER
#define FOPEN(_file, _filename, _mode) { if (fopen_s(&_file, _filename, _mode) != 0) _file = NULL; }
#define STRICMP _stricmp
#else
#define FOPEN(_file, _filename, _mode) _file = fopen(_filename, _mode)
#include <strings.h>
#define STRICMP strcasecmp
#endif

static bool s_verbose = false;

class Stopwatch
{
public:
	Stopwatch() { reset(); }
	void reset() { m_start = clock(); }
	double elapsed() const { return (clock() - m_start) * 1000.0 / CLOCKS_PER_SEC; }
private:
	clock_t m_start;
};

static int Print(const char* format, ...)
{
	va_list arg;
	va_start(arg, format);
	printf("\r"); // Clear progress text (PrintProgress).
	const int result = vprintf(format, arg);
	va_end(arg);
	return result;
}

static void PrintProgress(const char* name, const char* indent1, const char* indent2, int progress, Stopwatch* stopwatch)
{
	if (s_verbose)
		return;
	if (progress == 0)
		stopwatch->reset();
	printf("\r%s%s [", indent1, name);
	for (int i = 0; i < 10; i++)
		printf(progress / ((i + 1) * 10) ? "*" : " ");
	printf("] %d%%", progress);
	fflush(stdout);
	if (progress == 100)
		printf("\n%s%.2f seconds (%g ms) elapsed\n", indent2, stopwatch->elapsed() / 1000.0, stopwatch->elapsed());
}

static bool ProgressCallback(xatlas::ProgressCategory::Enum category, int progress, void* userData)
{
	Stopwatch* stopwatch = (Stopwatch*)userData;
	PrintProgress(xatlas::StringForEnum(category), "   ", "      ", progress, stopwatch);
	return true;
}

static void RandomColor(uint8_t* color)
{
	for (int i = 0; i < 3; i++)
		color[i] = uint8_t((rand() % 255 + 192) * 0.5f);
}

static void SetPixel(uint8_t* dest, int destWidth, int x, int y, const uint8_t* color)
{
	uint8_t* pixel = &dest[x * 3 + y * (destWidth * 3)];
	pixel[0] = color[0];
	pixel[1] = color[1];
	pixel[2] = color[2];
}

// https://github.com/miloyip/line/blob/master/line_bresenham.c
// License: public domain.
static void RasterizeLine(uint8_t* dest, int destWidth, const int* p1, const int* p2, const uint8_t* color)
{
	const int dx = abs(p2[0] - p1[0]), sx = p1[0] < p2[0] ? 1 : -1;
	const int dy = abs(p2[1] - p1[1]), sy = p1[1] < p2[1] ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2;
	int current[2];
	current[0] = p1[0];
	current[1] = p1[1];
	while (SetPixel(dest, destWidth, current[0], current[1], color), current[0] != p2[0] || current[1] != p2[1])
	{
		const int e2 = err;
		if (e2 > -dx) { err -= dy; current[0] += sx; }
		if (e2 < dy) { err += dx; current[1] += sy; }
	}
}

static void RasterizeTriangle(uint8_t* dest, int destWidth, const int* t0, const int* t1, const int* t2, const uint8_t* color)
{
	if (t0[1] > t1[1]) std::swap(t0, t1);
	if (t0[1] > t2[1]) std::swap(t0, t2);
	if (t1[1] > t2[1]) std::swap(t1, t2);
	int total_height = t2[1] - t0[1];
	for (int i = 0; i < total_height; i++) {
		bool second_half = i > t1[1] - t0[1] || t1[1] == t0[1];
		int segment_height = second_half ? t2[1] - t1[1] : t1[1] - t0[1];
		float alpha = (float)i / total_height;
		float beta = (float)(i - (second_half ? t1[1] - t0[1] : 0)) / segment_height;
		int A[2], B[2];
		for (int j = 0; j < 2; j++) {
			A[j] = int(t0[j] + (t2[j] - t0[j]) * alpha);
			B[j] = int(second_half ? t1[j] + (t2[j] - t1[j]) * beta : t0[j] + (t1[j] - t0[j]) * beta);
		}
		if (A[0] > B[0]) std::swap(A, B);
		for (int j = A[0]; j <= B[0]; j++)
			SetPixel(dest, destWidth, j, t0[1] + i, color);
	}
}

namespace MyXatlas
{
	struct outPosition
	{
		float x, y, z;
	};

	struct outNormal
	{
		float x, y, z;
	};

	struct outTexCoords
	{
		float u, v;
	};

	struct outVertex
	{
		outPosition outP;//输出位置
		outNormal outN;//输出法向
		outTexCoords outT;//输出纹理
		std::vector<int> Index;
	};

	std::vector<outVertex> GenerateUV(std::vector<float> v, std::vector<float> vn, std::vector<int> vi)
	{
		std::vector<outVertex> outV;
		// Load object file.
		std::vector<tinyobj::shape_t> shapes;
		std::vector<tinyobj::material_t> materials;
		std::string err;
		
		if (!tinyobj::ExportFace(shapes, v, vn, vi, err, tinyobj::triangulation))
		{
			printf("Error: %s\n", err.c_str());
			return outV;
		}

		if (shapes.size() == 0) {
			printf("Error: no shapes in obj file\n");
			return outV;
		}
		printf("   %d shapes\n", (int)shapes.size());
		// Create empty atlas.
		xatlas::SetPrint(Print, s_verbose);
		xatlas::Atlas* atlas = xatlas::Create();
		// Set progress callback.
		Stopwatch globalStopwatch, stopwatch;
		xatlas::SetProgressCallback(atlas, ProgressCallback, &stopwatch);
		// Add meshes to atlas.
		uint32_t totalVertices = 0, totalFaces = 0;
		for (int i = 0; i < (int)shapes.size(); i++) {
			const tinyobj::mesh_t& objMesh = shapes[i].mesh;
			xatlas::MeshDecl meshDecl;
			meshDecl.vertexCount = (uint32_t)objMesh.positions.size() / 3;
			meshDecl.vertexPositionData = objMesh.positions.data();
			meshDecl.vertexPositionStride = sizeof(float) * 3;
			if (!objMesh.normals.empty()) {
				meshDecl.vertexNormalData = objMesh.normals.data();
				meshDecl.vertexNormalStride = sizeof(float) * 3;
			}
			if (!objMesh.texcoords.empty()) {
				meshDecl.vertexUvData = objMesh.texcoords.data();
				meshDecl.vertexUvStride = sizeof(float) * 2;
			}
			meshDecl.indexCount = (uint32_t)objMesh.indices.size();
			meshDecl.indexData = objMesh.indices.data();
			meshDecl.indexFormat = xatlas::IndexFormat::UInt32;
			xatlas::AddMeshError::Enum error = xatlas::AddMesh(atlas, meshDecl, (uint32_t)shapes.size());
			if (error != xatlas::AddMeshError::Success) {
				xatlas::Destroy(atlas);
				printf("\rError adding mesh %d '%s': %s\n", i, shapes[i].name.c_str(), xatlas::StringForEnum(error));
				return outV;
			}
			totalVertices += meshDecl.vertexCount;
			totalFaces += meshDecl.indexCount / 3;
		}
		xatlas::AddMeshJoin(atlas); // Not necessary. Only called here so geometry totals are printed after the AddMesh progress indicator.
		printf("   %u total vertices\n", totalVertices);
		printf("   %u total triangles\n", totalFaces);
		// Generate atlas.
		printf("Generating atlas\n");
		xatlas::Generate(atlas);
		printf("   %d charts\n", atlas->chartCount);
		printf("   %d atlases\n", atlas->atlasCount);
		for (uint32_t i = 0; i < atlas->atlasCount; i++)
			printf("      %d: %0.2f%% utilization\n", i, atlas->utilization[i] * 100.0f);
		printf("   %ux%u resolution\n", atlas->width, atlas->height);
		totalVertices = totalFaces = 0;
		for (uint32_t i = 0; i < atlas->meshCount; i++) {
			const xatlas::Mesh& mesh = atlas->meshes[i];
			totalVertices += mesh.vertexCount;
			totalFaces += mesh.indexCount / 3;
		}
		printf("   %u total vertices\n", totalVertices);
		printf("   %u total triangles\n", totalFaces);
		printf("%.2f seconds (%g ms) elapsed total\n", globalStopwatch.elapsed() / 1000.0, globalStopwatch.elapsed());
		// Write meshes.
		const char* modelFilename = "C:/Users/liupu/Desktop/triangle.obj";
		printf("Writing '%s'...\n", modelFilename);
		FILE* file;
		FOPEN(file, modelFilename, "w");
		if (file) {
			uint32_t firstVertex = 0;
			for (uint32_t i = 0; i < atlas->meshCount; i++) {
				const xatlas::Mesh& mesh = atlas->meshes[i];
				for (uint32_t Currentv = 0; Currentv < mesh.vertexCount; Currentv++) {
					outVertex Temp;
					xatlas::Vertex& vertex = mesh.vertexArray[Currentv];
					const float* pos = &shapes[i].mesh.positions[vertex.xref * 3];
					fprintf(file, "v %g %g %g\n", pos[0], pos[1], pos[2]);
					Temp.outP.x = pos[0];
					Temp.outP.y = pos[1];
					Temp.outP.z = pos[2];

					if (!shapes[i].mesh.normals.empty()) {
						const float* normal = &shapes[i].mesh.normals[vertex.xref * 3];
						fprintf(file, "vn %g %g %g\n", normal[0], normal[1], normal[2]);
						Temp.outN.x = normal[0];
						Temp.outN.y = normal[1];
						Temp.outN.z = normal[2];
					}
					fprintf(file, "vt %g %g\n", vertex.uv[0] = vertex.uv[0] / atlas->width, vertex.uv[1] = vertex.uv[1] / atlas->height);
					Temp.outT.u = vertex.uv[0];
					Temp.outT.v = vertex.uv[1];

					outV.push_back(Temp);
				}
				fprintf(file, "o %s\n", shapes[i].name.c_str());
				fprintf(file, "s off\n");
				for (uint32_t f = 0; f < mesh.indexCount; f += 3) {
					fprintf(file, "f ");
					for (uint32_t j = 0; j < 3; j++) {
						const uint32_t index = firstVertex + mesh.indexArray[f + j] + 1; // 1-indexed
						fprintf(file, "%d/%d/%d%c", index, index, index, j == 2 ? '\n' : ' ');
						outV[0].Index.push_back(index);
					}
				}
				firstVertex += mesh.vertexCount;
			}
			fclose(file);
		}
		return outV;
	}
}
