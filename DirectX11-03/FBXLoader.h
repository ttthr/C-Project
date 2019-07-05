#pragma once
#include "DXUtility.h"
#include "Mesh.h"
#include <vector>
#include <fbxsdk.h>
#include "Vertex.h"

#pragma comment(lib, "libfbxsdk.lib")

using namespace std;

namespace FBXLoader
{
	//FBX 로드
	HRESULT LoadFBX(LPCSTR fileName, vector<Vertex>* outVertices, 
		vector<DWORD>* outIndices);

	//텍스쳐 좌표 읽어오는 함수
	XMFLOAT2 ReadTextureUV(FbxMesh* fbxMesh, int ControlPointIndex,
		int VerTexCounter);

	XMFLOAT3 ReadNormal(FbxMesh* fbxMesh, int ControlPointIndex,
		int VerTexCounter);

}

