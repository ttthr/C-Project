#include "Engine.h"

Engine::Engine(HINSTANCE hinstance) : DXApp(hinstance)
{

}

Engine::~Engine()
{
	Memory::SafeDelete(mesh);
	Memory::SafeDelete(mesh2);
	material->Release();
	material->Release();
	Memory::SafeDelete(material);
	Memory::SafeDelete(material2);
	Memory::SafeRelease(constantBuffer);
	Memory::SafeDelete(pCamera);
	
}

int Engine::Run()
{
	return window->Run(this);
}

bool Engine::Init()
{
	if (DXApp::Init() == false)
		return false;
	
	// ��� �ʱ�ȭ.
	if (InitializeScene() == false)
		return false;

	// ��� �ʱ�ȭ.
	if (InitializeTransformation() == false)
		return false;

	return true;
}

void Engine::Update()
{
	
	// ��/���� ��� ���ε�.
	deviceContext->VSSetConstantBuffers(1, 1, &constantBuffer);
}

void Engine::Render()
{
	float color[] = { 0.0f, 0.0f, 1.0f, 1.0f };

	// ���� Ÿ���� ������ �������� ĥ�ϱ�.
	deviceContext->ClearRenderTargetView(renderTargetView, color);

	// ����/���ٽ� �� �����.
	deviceContext->ClearDepthStencilView(depthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

	// ���� ��� ������Ʈ.
	mesh->Update(deviceContext);

	//���ε�
	//���͸��� ���ؽ��� �ȼ� �� ��������
	//���������� �̷���
	material->BindShaders(deviceContext);
	material->BindTexture(deviceContext);
	material->BindSamplerState(deviceContext);
	// �޽� ���� �׸���.
	mesh->RenderBuffers(deviceContext);

	// ���� ��� ������Ʈ.
	mesh2->Update(deviceContext);

	material2->BindShaders(deviceContext);
	material2->BindTexture(deviceContext);
	material2->BindSamplerState(deviceContext);

	// �޽� ���� �׸���.
	//mesh2->RenderBuffers(deviceContext);

	// ����� <-> ����Ʈ ���� ��ȯ.
	swapChain->Present(1, 0);
}

bool Engine::InitializeScene()
{
	//// ���� ���̴� ����.
	//vertexShader = new VertexShader(TEXT("Shader//Toon"));
	//// ���� ���̴� ������.
	//if (vertexShader->CompileShader(device) == false)
	//	return false;

	//// ���� ���̴� ��ü ����.
	//if (vertexShader->CreateShader(device) == false)
	//	return false;

	//// �ȼ� ���̴� ����.
	//pixelShader = new PixelShader(TEXT("Shader//Toon"));

	//// �ȼ� ���̴� ������.
	//if (material->GetPixelShader()->CompileShader(device) == false)
	//	return false;

	//// �ȼ� ���̴� ��ü ����.
	//if (pixelShader->CreateShader(device) == false)
	//	return false;

	//// �ؽ�ó �ε�.
	////if (pixelShader->LoadTexture(
	////	device,
	////	TEXT("Resources/Textures/T_Chr_FPS_D.png"))
	////	== false)
	////{
	////	return false;
	////}

	//// ���÷� ������Ʈ ����.
	//if (pixelShader->CreateSamplerState(device) == false)
	//	return false;

	//��Ƽ���� ��ü ����
	material = new Material(TEXT("Shader//Toon"));
	material2 = new Material(TEXT("Shader//Specular"));
	
	//�� ���̴� ��ü ����
	if (material->CompileShaders(device) == false)
	{
		return false;
	}
	if (material2->CompileShaders(device) == false)
	{
		return false;
	}
	//���͸��� ������
	if (material->CreateShaders(device) == false)
	{
		return false;
	}
	if (material2->CreateShaders(device) == false)
	{
		return false;
	}
	//�ؽ��� ����
	//�ؽ��� �߰�
	material->AddTexture(TEXT("Resources/Textures/T_Chr_FPS_D.png"));
	material2->AddTexture(TEXT("Resources/Textures/orange.png"));
	//�ؽ��� �ε�
	if (material->LoadTexture(device) == false)
	{
		return false;
	}
	if (material2->LoadTexture(device) == false)
	{
		return false;
	}
	//���÷� ������Ʈ ����
	if (material->CreateSamplerState(device) == false)
	{
		return false;
	}
	if (material2->CreateSamplerState(device) == false)
	{
		return false;
	}

	// �޽� ����.
	//mesh = new Mesh(0.0f, 0.0f, 0.0f);
	mesh = new Mesh("Resources/Models/HeroTPP.FBX");
	mesh->SetPosition(0.0f, -90.0f, 0.0f);
	mesh->SetRotation(-90.0f, 180.0f, 0.0f);
	// �ʱ�ȭ.
	if (mesh->InitializeBuffers(device, material) 
		== false)
		return false;

	mesh2 = new Mesh("Resources/Models/SK_CharM_Cardboard.FBX");
	mesh2->SetPosition(-100.0f, -90.0f, 0.0f);
	mesh2->SetRotation(-90.0f, 180.0f, 0.0f);
	// �ʱ�ȭ.
	if (mesh2->InitializeBuffers(device, material2)
		== false)
		return false;

	return true;
}

bool Engine::InitializeTransformation()
{
	// ���� ���.
	// �þ߰� / ��Ⱦ�� ����.
	float fovY = XMConvertToRadians(70.0f);
	float aspectRatio = static_cast<float>(window->GetScreenWidth()) / static_cast<float>(window->GetScreenHeight());
	
	// ī�޶� ���� ����.
	pCamera = new Camera(fovY, aspectRatio, 1.0f, 10000.0f);

	// ���ۿ� ���� ����ü ���� ����.
	PerSceneBuffer matrixData;
	matrixData.viewProjection = XMMatrixTranspose(pCamera->GetViewMatrix() * pCamera->GetProjMatrix());
	matrixData.worldLightPosition = XMFLOAT3(500.0f, 500.0f, -500.0f);
	matrixData.worldCameraPosition = pCamera->GetPosition(); // ( 0, 0 , -200)

	// ���� ����.
	// ���� ������.
	D3D11_BUFFER_DESC cbDesc;
	ZeroMemory(&cbDesc, sizeof(D3D11_BUFFER_DESC));

	cbDesc.ByteWidth = sizeof(PerSceneBuffer);
	cbDesc.CPUAccessFlags = 0;
	cbDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cbDesc.MiscFlags = 0;
	cbDesc.Usage = D3D11_USAGE_DEFAULT;

	// �ε��� �迭 ���� �־��� ����ü.
	D3D11_SUBRESOURCE_DATA cbData;
	ZeroMemory(&cbData, sizeof(D3D11_SUBRESOURCE_DATA));
	cbData.pSysMem = &matrixData;

	// ��� ���� ����.
	HRESULT result = device->CreateBuffer(&cbDesc, &cbData, &constantBuffer);
	if (IsError(result, TEXT("�� ��� ���� ���� ����")))
	{
		return false;
	}

	return true;
}