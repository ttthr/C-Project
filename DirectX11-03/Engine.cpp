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
	//엔진 루프
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

	//렌더 타겟을 설정한 색상으로 칠하기
	m_pd3dDeviceContext->ClearRenderTargetView(m_pRenderTargetView, color);

	//버텍스, 셰이더 바인딩 할 곳
	pVertexShader->BindShader(m_pd3dDeviceContext);
	pPixelShader->BindShader(m_pd3dDeviceContext);
	
	//메쉬 렌더
	pMesh->RenderBuffers(m_pd3dDeviceContext);

	//버퍼 교환
	m_pSwapChain->Present(1, 0);
}

bool Engine::InitializeScene()
{
	//버텍스 셰이더 생성
	pVertexShader = new VertexShader(TEXT("Shader//VS.fx"));
	//버텍스 셰이더 컴파일
	if (pVertexShader->CompileShader(m_pd3dDevice) == false)
	{
		return false;
	}
	//정점 셰이더 객체 생성
	if (pVertexShader->CreateShader(m_pd3dDevice) == false)
	{
		return false;
	}
	//픽셀 셰이더 생성
	pPixelShader = new PixelShader(TEXT("Shader//PS.fx"));
	//픽셀 셰이더 컴파일
	if (pPixelShader->CompileShader(m_pd3dDevice) == false)
	{
		return false;
	}
	//픽셀 셰이더 객체 생성
	if (pPixelShader->CreateShader(m_pd3dDevice) == false)
	{
		return false;
	}

	//메쉬 생성
	pMesh = new Mesh();
	//초기화
	if (pMesh->InitailizeBuffers(m_pd3dDevice, pVertexShader->GetShaderBuffer()) == false)
	{
		return false;
	}

	return true;
}
