#include "DXApp.h"

DXApp::DXApp(HINSTANCE hInstance)
{
	//������ ��ü ����
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
	//������ â �ʱ�ȭ
	if (window->InitWindow() == false)
	{
		return false;
	}
	// ���̷�ƮX �ʱ�ȭ
	if (InitializeDirect3D() == false)
	{
		return false;
	}

	return true;
}

bool DXApp::InitializeDirect3D()
{
	//����ü�λ��� 
	//������ ( Descriptor )

	DXGI_SWAP_CHAIN_DESC swapDesc;
	ZeroMemory(&swapDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
	swapDesc.BufferCount = 1; //����۸� �ϳ��� �дٴ� ���
	swapDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; 
	swapDesc.OutputWindow = window->GetHwnd(); //�׷��� �� â��
	swapDesc.Windowed = TRUE; //���߿� Ǯ��ũ���Ҷ� �ǵ������
	swapDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD; //����
	swapDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; //��ֶ�����Ȱ��� ���� 0~1����
	swapDesc.BufferDesc.Width = window->GetscreenWidth();
	swapDesc.BufferDesc.Height = window->GetscreenHeight();
	swapDesc.SampleDesc.Count = 1; // ���ø� ���ϰڴ�.
	swapDesc.SampleDesc.Quality = 0;

	HRESULT hResult;
	hResult = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, NULL,
		NULL, NULL, D3D11_SDK_VERSION, &swapDesc, &m_pSwapChain, &m_pd3dDevice, NULL,
		&m_pd3dDeviceContext);

	//����Ȯ��
	if (FAILED(hResult))
	{
		MessageBox(NULL, TEXT("��ġ ���� ����"), TEXT("����"), MB_OK);
		return false;
	}

	//����� ����� ( ������ �ؽ��� )
	ID3D11Texture2D* pBackBufferTexture2D;
	hResult = m_pSwapChain->GetBuffer(NULL, __uuidof(ID3D11Texture2D), (void**)&pBackBufferTexture2D);
	
	//����Ȯ��
	if (FAILED(hResult))
	{
		MessageBox(NULL, TEXT("���ۼ� ���� ����"), TEXT("����"), MB_OK);
		return false;
	}

	//���� Ÿ�� �� ����( ����۰� ���� ��) 

	hResult = m_pd3dDevice->CreateRenderTargetView(pBackBufferTexture2D, NULL, &m_pRenderTargetView);

	//����Ȯ��
	if (FAILED(hResult))
	{
		MessageBox(NULL, TEXT("���� Ÿ�� �� ���� ����"), TEXT("����"), MB_OK);
		return false;
	}

	//���� Ÿ�ٿ� ���� 
	m_pd3dDeviceContext->OMSetRenderTargets(1, &m_pRenderTargetView, NULL);

	//���� ������ ���� ����ߴ� �ڿ�(����) ����
	pBackBufferTexture2D->Release();

	return true;
}
