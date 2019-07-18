#pragma once
#include "DXUtil.h"
#include "Vertex.h"
#include "Mesh.h"

using namespace std;
using namespace DirectX;

class RTRenderer
{
public:
	RTRenderer();
	~RTRenderer();
private:
	ID3D11Buffer* vertexBuffer;
	ID3D11Buffer* indexBuffer;
	ID3D11InputLayout* inputLayout;
	D3D11_INPUT_ELEMENT_DESC inputLayoutDesc[5] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TANGENT", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "BINORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },

	};
	int vertexCount;
	int indexCount;
	int screenWidth;
	int screenHeight;
	int bitmapWidth;
	int bitmapHeight;
	Vertex vertices[4];
	ID3D11Buffer* constantBuffer;
	Mesh::PerObjectBuffer matrixData;
public:
	bool Initiailze(ID3D11Device* pd3dDevice , ID3DBlob* vertexShaderBuffer,
		int screenWidth , int screenHeight,
		int bitmapWidth , int bitmapHeight);

	void UpdateBuffers(ID3D11DeviceContext* pd3dDeviceContext, int posX , int posY);
	void RenderBuffers(ID3D11DeviceContext* pd3dDeviceCOntext);
	void Release();
};

