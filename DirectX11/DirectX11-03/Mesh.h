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
	int nVertices; // ���� ���� ������ ����
	ID3D11Buffer* VertexBuffer; //���� ���� ������ ����
	ID3D11InputLayout* inputLayout; // �Է� ���̾ƿ� ( �׷��� ī�尡 �Ǵ��� ����)
	UINT Stride;
	UINT Offset;
public:
	bool InitailizeBuffers(ID3D11Device* pDevice, ID3DBlob* VertexShaderBuffer);
	void RenderBuffers(ID3D11DeviceContext* pDeviceContext);
};

