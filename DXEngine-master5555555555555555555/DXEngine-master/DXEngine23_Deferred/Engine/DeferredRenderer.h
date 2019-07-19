#pragma once
#include "DXUtil.h"
#include "Camera.h"

class DeferredRenderer : 
	public AlignedAllocation<16>
{
public:
	DeferredRenderer();
	~DeferredRenderer();
public:
	struct DeferredVertex
	{
		XMFLOAT3 position;
		XMFLOAT2 textureCoord;

		DeferredVertex() { ZeroMemory(this, sizeof(this)); }
	};
private:
	int vertexCount;
	int indexCount;
	ID3D11Buffer* vertexBuffer;
	ID3D11Buffer* indexBuffer;
	ID3D11Buffer* constantBuffer;
	XMMATRIX view = XMMatrixIdentity();
	XMMATRIX proj = XMMatrixIdentity();
	ID3D11InputLayout* inputLayout;
	D3D11_INPUT_ELEMENT_DESC inputLayoutDesc[2] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};
public:
	bool Initialize(ID3D11Device* pd3dDevice, ID3DBlob* pVertexShaderBuffer, Camera* pCamera , UINT screenWidth , UINT screenHeight);
	void DiferredRender(ID3D11DeviceContext* pd3dDeviceContext);
	void DiferredUpdate(ID3D11DeviceContext* pd3dDeviceContext);
	void Release();
public:
	XMMATRIX GetDifferdView() const { return view; }
	XMMATRIX GetDifferdProj() const { return proj; }
};

