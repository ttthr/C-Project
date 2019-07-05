#pragma once
#include "DXUtility.h"
#include "Vertex.h"
#include <vector>


class FBXLodder;
using namespace DirectX;
using namespace std;

class Mesh
{
public:
	Mesh();
	Mesh(float x, float y , float z);
	Mesh(LPCSTR FbxFileName);
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
	XMFLOAT3 Position = XMFLOAT3(0.0f, 0.0f, 0.0f); //��ġ ����
	ID3D11Buffer* ConstantBuffer; //��� ����( ���� ��� ������ ������ ����)
	//2019.07.05
	XMFLOAT3 Rotation = XMFLOAT3(0.0f, 0.0f, 0.0f); //ȸ�� ����
	XMFLOAT3 Scale = XMFLOAT3(1.0f, 1.0f, 1.0f);  //������ ����
	XMMATRIX WorldMatrix;
private:
	//2019.07.05 
	LPCSTR FbxFileName; //FBX���� �̸�
	vector<Vertex> vertices; //���� �迭
	vector<DWORD> indices;  //�ε��� �迭
	D3D11_INPUT_ELEMENT_DESC inputLayoutDesc[3] =
	{

		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};
public:
	bool InitailizeBuffers(ID3D11Device* pDevice, ID3DBlob* VertexShaderBuffer);
	void RenderBuffers(ID3D11DeviceContext* pDeviceContext);
	void Update(ID3D11DeviceContext* pDeviceContext);
public:
	// ����,��,�������� (2019.07.03 5�� 10�� ����)
	// �������� �����ϴ� 3D ���� ����
	// �����ڸ� ���� ���� ����
	XMFLOAT3 GetPosition() const { return Position; }
	XMMATRIX GetWorldMatrix();
	//2019.07.05
	XMMATRIX GetTranslationMatrix();
	XMMATRIX GetRotationMatrix();
	XMMATRIX GetScaleMatrix();
	void SetPosition(float x, float y, float z);
public:
	//2019.07.05
	XMFLOAT3 GetRotation() const { return Rotation; }
	XMFLOAT3 GetScale() const { return Scale; }
	void SetRotation(float x, float y, float z);
	void SetScale(float x, float y, float z);
	LPCSTR GetFbxName() const { return FbxFileName; }
	vector<Vertex>* GetVectorArray() { return &vertices; }
	vector<DWORD>* GetIndexArry() { return &indices; }
	int GetVerTexCount() const { return vertices.size(); }
	int GetIndexCount() const { return indices.size(); }
	D3D11_INPUT_ELEMENT_DESC* GetInputLayoutDesc() { return inputLayoutDesc; }

};

