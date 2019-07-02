#pragma once
#include "DXUtility.h"


using namespace DirectX;

class Mesh
{
public:
	Mesh();
	virtual ~Mesh();
private:
	struct Vertex
	{
		XMFLOAT3 xmPosition;
		Vertex(float x, float y, float z) :
			xmPosition(x, y, z){}

	};
private:
	int nVertices; // 정점 갯수 저장할 변수
	ID3D11Buffer* VertexBuffer; //정점 정보 저장할 버퍼
	ID3D11InputLayout* inputLayout; // 입력 레이아웃 ( 그래픽 카드가 판단할 내용)
	UINT Stride;
	UINT Offset;
public:
	bool InitailizeBuffers(ID3D11Device* pDevice, ID3DBlob* VertexShaderBuffer);
	void RenderBuffers(ID3D11DeviceContext* pDeviceContext);
};

