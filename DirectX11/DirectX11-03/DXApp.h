#pragma once
#include "AppWindow.h"
#include "DXUtility.h"


class DXApp
{
public:
	DXApp(HINSTANCE hInstance);
	virtual ~DXApp();
protected:
	AppWindow* window;
public:
	virtual int Run() = 0;
	virtual bool Init();
	virtual void Update() = 0;
	virtual void Render() = 0;

public:
	ID3D11Device* m_pd3dDevice;
	ID3D11DeviceContext* m_pd3dDeviceContext;
	IDXGISwapChain* m_pSwapChain;
	ID3D11RenderTargetView* m_pRenderTargetView;
protected:
	bool InitializeDirect3D();
	void SetViewPort();
};

