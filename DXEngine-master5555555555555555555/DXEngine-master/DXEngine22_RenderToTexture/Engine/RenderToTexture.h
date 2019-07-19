#pragma once
#include "DXUtil.h"
#include "Camera.h"

using namespace DirectX;
using namespace std;

class RenderToTexture 
	: public AlignedAllocation<16>
{
public:
	RenderToTexture();
	~RenderToTexture();
private:
	ID3D11Texture2D* RenderTagetTexture2D;
	ID3D11RenderTargetView* RenderTagetView;
	ID3D11ShaderResourceView* RenderTargetShaderResoureView;
	XMMATRIX view;
	XMMATRIX projection;
public:
	ID3D11Texture2D* GetRenderTargetTexture2D() const { return RenderTagetTexture2D; }
	ID3D11RenderTargetView* GetRenderTagetView() const { return RenderTagetView; }
	ID3D11ShaderResourceView* GetRenderTargetShaderResoureView() const { return RenderTargetShaderResoureView; }
	XMMATRIX GetProjectionMatrix() const { return projection; }
	XMMATRIX GetViewMatrix() const { return view; }
public:
	bool Initialize(ID3D11Device* pd3dDevice , Camera* pCamera , int width , int height);
	void SetRenderTarget(ID3D11DeviceContext* pd3dDeviceContext, ID3D11DepthStencilView* pDepthStencilView);
	void ClearRenderTarget(ID3D11DeviceContext* pd3dDeviceContext , ID3D11DepthStencilView* pDepthStencilView  , float color[]);
	void Release();

};


