#pragma once
#include "DXUtil.h"
using namespace DirectX;

#define BUFFERCOUNT 2

class DeferredBuffer
{
public:
	DeferredBuffer();
	~DeferredBuffer();
private:
	int textureWidth;
	int textureHeight;
	ID3D11Texture2D* renderTargetTExtureArray[BUFFERCOUNT];
	ID3D11RenderTargetView* renderTargetViewArray[BUFFERCOUNT];
	ID3D11ShaderResourceView* renderTargetSRVArray[BUFFERCOUNT];

public:
	ID3D11Texture2D* GetTexture2D(int index) { return renderTargetTExtureArray[index]; }
	ID3D11RenderTargetView* GetRenderTarget (int index) { return renderTargetViewArray[index]; }
	ID3D11ShaderResourceView* GetShaderResourceView (int index) { return renderTargetSRVArray[index]; }
public:
	bool Initailize(ID3D11Device* pd3dDevice, int width, int height);
	void SetRenderTargets(ID3D11DeviceContext* pd3dDeviceContext, ID3D11DepthStencilView* pd3dDepthStencilView);
	void ClearRenderTargets(ID3D11DeviceContext* pd3dDeviceContext, ID3D11DepthStencilView* pd3dDepthStencilView , float color[]);
	void Release();
};

