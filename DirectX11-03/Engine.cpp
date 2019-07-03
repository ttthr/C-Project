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
	//DX�ʱ�ȭ
	if (DXApp::Init() == false)
	{
		return false;
	}
	//��� �ʱ�ȭ
	if (InitializeScene() == false)
	{
		return false;
	}
	// ��� �ʱ�ȭ
	if (InitializeTransformation() == false)
	{
		return false;
	}
	return true;
}

void Engine::Update()
{
	//���� ��� ������Ʈ
	pMesh->Update(m_pd3dDeviceContext);
	// ��,������� ������۷� �ѱ��
	m_pd3dDeviceContext->VSSetConstantBuffers(1, 1, &ViewProjConstantBuffer);
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
	pMesh = new Mesh(0.0f,0.0f, 0.0f);
	//�ʱ�ȭ
	if (pMesh->InitailizeBuffers(m_pd3dDevice, pVertexShader->GetShaderBuffer()) == false)
	{
		return false;
	}

	return true;
}

bool Engine::InitializeTransformation()
{
	//ī�޶� ���� ����
	CameraPosition = XMVectorSet(0.0f, 0.0f, -2.0f, 0.0f);
	CameraView = XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
	CameraUp = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

	//�� ��� �����
	XMMATRIX ViewMatrix;
	ViewMatrix = XMMatrixLookAtLH(CameraPosition, CameraView, CameraUp);

	//���� ��� 
	//�þ߰� / ��Ⱦ�� ����
	float fovY = XMConvertToRadians(70.0f);
	float AspectRatio = static_cast<float>(window->GetscreenWidth()) / static_cast<float>(window->GetscreenHeight());

	XMMATRIX ProjMatrix;
	ProjMatrix = XMMatrixPerspectiveFovLH(fovY, AspectRatio, 1.0f, 1000.0f);

	//���ۿ� ���� ����ü ���� ����
	PerSceneBuffer MatrixData;
	MatrixData.ViewMatrix = XMMatrixTranspose(ViewMatrix);
	MatrixData.ProjMatrix = XMMatrixTranspose(ProjMatrix);

	// ���� ����
	D3D11_BUFFER_DESC MatrixBufferDesc; //������
	ZeroMemory(&MatrixBufferDesc, sizeof(D3D11_BUFFER_DESC)); //�ʱ�ȭ
	MatrixBufferDesc.ByteWidth = sizeof(PerSceneBuffer); //����Ʈ �� ���
	MatrixBufferDesc.CPUAccessFlags = 0; // CPU�� ���ٸ��ϰ� 0���� �������ָ��
	MatrixBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER; // ���ؽ� ���� ���
	MatrixBufferDesc.MiscFlags = 0; //���۸� �ٸ��뵵�� ���鶧 �ִ� ��
	MatrixBufferDesc.Usage = D3D11_USAGE_DEFAULT; //CPU�� ���ٸ��� 

	//���� �迭 ������ �־��� ����ü
	D3D11_SUBRESOURCE_DATA MatrixSubResouceVB;
	ZeroMemory(&MatrixSubResouceVB, sizeof(D3D11_SUBRESOURCE_DATA));
	MatrixSubResouceVB.pSysMem = &MatrixData;

	//���� ���� ����
	HRESULT hResult;
	hResult = m_pd3dDevice->CreateBuffer(&MatrixBufferDesc, &MatrixSubResouceVB, &ViewProjConstantBuffer);

	if (FAILED(hResult))
	{
		MessageBox(NULL, TEXT("�� ������� ���� ����"), TEXT("����"), MB_OK);
		return false;
	}
	return true;
}
