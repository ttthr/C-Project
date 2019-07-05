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
	//FBX �ε�
	HRESULT LoadFBX(LPCSTR fileName, vector<Vertex>* outVertices, 
		vector<DWORD>* outIndices);

	//�ؽ��� ��ǥ �о���� �Լ�
	XMFLOAT2 ReadTextureUV(FbxMesh* fbxMesh, int ControlPointIndex,
		int VerTexCounter);

	XMFLOAT3 ReadNormal(FbxMesh* fbxMesh, int ControlPointIndex,
		int VerTexCounter);

}

