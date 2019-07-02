#include "DXApp.h"

DXApp::DXApp(HINSTANCE hInstance)
{
	//윈도우 객체 생성
	window = new AppWindow(hInstance);

}
DXApp::~DXApp()
{
	if (window != NULL)
	{
		delete window;
	}

	m_pd3dDevice->Release();
	m_pd3dDeviceContext->Release();
	m_pSwapChain->Release();
	m_pRenderTargetView->Release();

}
bool DXApp::Init()
{
	//윈도우 창 초기화
	if (window->InitWindow() == false)
	{
		return false;
	}
	// 다이렉트X 초기화
	if (InitializeDirect3D() == false)
	{
		return false;
	}

	return true;
}

bool DXApp::InitializeDirect3D()
{
	//스왑체인생성 
	//서술자 ( Descriptor )

	DXGI_SWAP_CHAIN_DESC swapDesc;
	ZeroMemory(&swapDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
	swapDesc.BufferCount = 1; //백버퍼를 하나만 둔다는 얘기
	swapDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; 
	swapDesc.OutputWindow = window->GetHwnd(); //그려야 할 창값
	swapDesc.Windowed = TRUE; //나중에 풀스크린할때 건드려야함
	swapDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD; //없음
	swapDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; //노멀라이즈된값이 들어간다 0~1사이
	swapDesc.BufferDesc.Width = window->GetscreenWidth();
	swapDesc.BufferDesc.Height = window->GetscreenHeight();
	swapDesc.SampleDesc.Count = 1; // 샘플링 안하겠다.
	swapDesc.SampleDesc.Quality = 0;

	HRESULT hResult;
	hResult = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, NULL,
		NULL, NULL, D3D11_SDK_VERSION, &swapDesc, &m_pSwapChain, &m_pd3dDevice, NULL,
		&m_pd3dDeviceContext);

	//오류확인
	if (FAILED(hResult))
	{
		MessageBox(NULL, TEXT("장치 생성 실패"), TEXT("오류"), MB_OK);
		return false;
	}

	//백버퍼 만들기 ( 실제로 텍스쳐 )
	ID3D11Texture2D* pBackBufferTexture2D;
	hResult = m_pSwapChain->GetBuffer(NULL, __uuidof(ID3D11Texture2D), (void**)&pBackBufferTexture2D);
	
	//오류확인
	if (FAILED(hResult))
	{
		MessageBox(NULL, TEXT("백퍼서 생성 실패"), TEXT("오류"), MB_OK);
		return false;
	}

	//랜더 타겟 뷰 생성( 백버퍼가 사용된 곳) 

	hResult = m_pd3dDevice->CreateRenderTargetView(pBackBufferTexture2D, NULL, &m_pRenderTargetView);

	//오류확인
	if (FAILED(hResult))
	{
		MessageBox(NULL, TEXT("렌더 타겟 뷰 생성 실패"), TEXT("오류"), MB_OK);
		return false;
	}

	//렌더 타겟에 연결 
	m_pd3dDeviceContext->OMSetRenderTargets(1, &m_pRenderTargetView, NULL);

	//버퍼 생성을 위해 사용했던 자원(버퍼) 해제
	pBackBufferTexture2D->Release();

	return true;
}
