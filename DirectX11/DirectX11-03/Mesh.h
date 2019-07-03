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
		XMFLOAT4 xmColor;
		Vertex(float x, float y, float z) :
			xmPosition(x, y, z){}
		Vertex(XMFLOAT3 pos) : xmPosition(pos){}
		Vertex(XMFLOAT3 pos , XMFLOAT4 color) : xmPosition(pos), xmColor(color) {}
	};
private:
	int nVertices; // ���� ���� ������ ����
	ID3D11Buffer* VertexBuffer; //���� ���� ������ ����
	ID3D11InputLayout* inputLayout; // �Է� ���̾ƿ� ( �׷��� ī�尡 �Ǵ��� ����)
	UINT Stride;
	UINT Offset;
private:
	//�ε��� ���� ( 2019.07.03 4�� ����)
	ID3D11Buffer* IndexBuffer; //�ε��� ������ ����
	int nIndeices; //�ε��� ����

public:
	bool InitailizeBuffers(ID3D11Device* pDevice, ID3DBlob* VertexShaderBuffer);
	void RenderBuffers(ID3D11DeviceContext* pDeviceContext);
};

