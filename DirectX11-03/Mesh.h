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
	//오브젝트마다 사용할 버퍼
	struct PerObjectBuffer 
	{
		PerObjectBuffer()
		{
			ZeroMemory(&World, sizeof(this));
		}
		XMMATRIX World;

	};
private:
	int nVertices; // 정점 갯수 저장할 변수
	ID3D11Buffer* VertexBuffer; //정점 정보 저장할 버퍼
	ID3D11InputLayout* inputLayout; // 입력 레이아웃 ( 그래픽 카드가 판단할 내용)
	UINT Stride;
	UINT Offset;
private:
	//인덱스 버퍼 ( 2019.07.03 4시 시작)
	ID3D11Buffer* IndexBuffer; //인덱스 저장할 버퍼
	int nIndeices; //인덱스 개수
private:
	// 월드,뷰,프로젝션 (2019.07.03 5시 10분 시작)
	XMFLOAT3 Position; //위치 정보
	ID3D11Buffer* ConstantBuffer; //상수 버퍼( 월드 행렬 정보를 보내는 버퍼)
public:
	bool InitailizeBuffers(ID3D11Device* pDevice, ID3DBlob* VertexShaderBuffer);
	void RenderBuffers(ID3D11DeviceContext* pDeviceContext);
	void Update(ID3D11DeviceContext* pDeviceContext);
public:
	// 월드,뷰,프로젝션 (2019.07.03 5시 10분 시작)
	// 수학으로 시작하는 3D 게임 개발
	// 수포자를 위한 게임 수학
	XMFLOAT3 GetPosition() const { return Position; }
	XMMATRIX GetWorldMatrix() const;
	void SetPosition(float x, float y, float z);
};

