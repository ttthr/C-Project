#include "Engine.h"


Engine::Engine(HINSTANCE hInstance)
	:DXApp(hInstance)
{


}

Engine::~Engine()
{
	//Memory::SafeDelete(pMesh);
	//pVertexShader->Release();
	//Memory::SafeDelete(pVertexShader);
	//pPixelShader->Release();
	//Memory::SafeDelete(pPixelShader);
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
	if (InitializeScene() == false)
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

	//���ؽ�, ���̴� ���ε� �� ��
	pVertexShader->BindShader(m_pd3dDeviceContext);
	pPixelShader->BindShader(m_pd3dDeviceContext);
	
	//�޽� ����
	pMesh->RenderBuffers(m_pd3dDeviceContext);

	//���� ��ȯ
	m_pSwapChain->Present(1, 0);
}

bool Engine::InitializeScene()
{
	//���ؽ� ���̴� ����
	pVertexShader = new VertexShader(TEXT("Shader//VS.fx"));
	//���ؽ� ���̴� ������
	if (pVertexShader->CompileShader(m_pd3dDevice) == false)
	{
		return false;
	}
	//���� ���̴� ��ü ����
	if (pVertexShader->CreateShader(m_pd3dDevice) == false)
	{
		return false;
	}
	//�ȼ� ���̴� ����
	pPixelShader = new PixelShader(TEXT("Shader//PS.fx"));
	//�ȼ� ���̴� ������
	if (pPixelShader->CompileShader(m_pd3dDevice) == false)
	{
		return false;
	}
	//�ȼ� ���̴� ��ü ����
	if (pPixelShader->CreateShader(m_pd3dDevice) == false)
	{
		return false;
	}

	//�޽� ����
	pMesh = new Mesh();
	//�ʱ�ȭ
	if (pMesh->InitailizeBuffers(m_pd3dDevice, pVertexShader->GetShaderBuffer()) == false)
	{
		return false;
	}

	return true;
}
