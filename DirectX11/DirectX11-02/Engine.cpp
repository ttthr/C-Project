#include "Engine.h"


Engine::Engine(HINSTANCE hInstance)
	:DXApp(hInstance)
{


}

Engine::~Engine()
{
}

int Engine::Run()
{
	//엔진 루프
	return window->Run(this);
}

bool Engine::Init()
{
	if (DXApp::Init() == false)
	{
		return false;
	}
	return true;
}

void Engine::Update()
{
}

void Engine::Render()
{
	float color[]{ 0.0f, 0.0f, 1.0f , 1.0f };

	//렌더 타겟을 설정한 색상으로 칠하기
	m_pd3dDeviceContext->ClearRenderTargetView(m_pRenderTargetView, color);

	//버퍼 교환
	m_pSwapChain->Present(1, 0);
}
