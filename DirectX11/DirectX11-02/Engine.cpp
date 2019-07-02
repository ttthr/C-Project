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
	//���� ����
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

	//���� Ÿ���� ������ �������� ĥ�ϱ�
	m_pd3dDeviceContext->ClearRenderTargetView(m_pRenderTargetView, color);

	//���� ��ȯ
	m_pSwapChain->Present(1, 0);
}
