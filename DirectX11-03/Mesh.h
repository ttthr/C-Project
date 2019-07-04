#pragma once
#include "DXUtility.h"
#include "Vertex.h"

using namespace DirectX;

class Mesh
{
public:
	Mesh();
	Mesh(float x, float y , float z);
	virtual ~Mesh();
private:
	//struct Vertex
	//{
	//	XMFLOAT3 xmPosition;
	//	XMFLOAT4 xmColor;
	//	XMFLOAT2 xmUV;
	//	Vertex(float x, float y, float z) :
	//		xmPosition(x, y, z){}
	//	Vertex(XMFLOAT3 pos) : xmPosition(pos){}
	//	Vertex(XMFLOAT3 pos , XMFLOAT4 color) : xmPosition(pos), xmColor(color) {}
	//	Vertex(XMFLOAT3 pos , XMFLOAT4 color, XMFLOAT2 uv) : xmPosition(pos), xmColor(color), xmUV(uv){}
	//};
	//������Ʈ���� ����� ����
	struct PerObjectBuffer 
	{
		PerObjectBuffer()
		{
			ZeroMemory(&World, sizeof(this));
		}
		XMMATRIX World;

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
private:
	// ����,��,�������� (2019.07.03 5�� 10�� ����)
	XMFLOAT3 Position; //��ġ ����
	ID3D11Buffer* ConstantBuffer; //��� ����( ���� ��� ������ ������ ����)
public:
	bool InitailizeBuffers(ID3D11Device* pDevice, ID3DBlob* VertexShaderBuffer);
	void RenderBuffers(ID3D11DeviceContext* pDeviceContext);
	void Update(ID3D11DeviceContext* pDeviceContext);
public:
	// ����,��,�������� (2019.07.03 5�� 10�� ����)
	// �������� �����ϴ� 3D ���� ����
	// �����ڸ� ���� ���� ����
	XMFLOAT3 GetPosition() const { return Position; }
	XMMATRIX GetWorldMatrix() const;
	void SetPosition(float x, float y, float z);
};

