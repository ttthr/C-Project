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
	
	// 장면 초기화.
	if (InitializeScene() == false)
		return false;

	// 행렬 초기화.
	if (InitializeTransformation() == false)
		return false;

	return true;
}

void Engine::Update()
{
	
	// 뷰/투영 행렬 바인딩.
	deviceContext->VSSetConstantBuffers(1, 1, &constantBuffer);
}

void Engine::Render()
{
	float color[] = { 0.0f, 0.0f, 1.0f, 1.0f };

	// 렌더 타겟을 설정한 색상으로 칠하기.
	deviceContext->ClearRenderTargetView(renderTargetView, color);

	// 뎁스/스텐실 뷰 지우기.
	deviceContext->ClearDepthStencilView(depthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

	// 월드 행렬 업데이트.
	mesh->Update(deviceContext);

	//바인딩
	//머터리얼에 버텍스랑 픽셀 다 묶여있음
	//엔진구조가 이러함
	material->BindShaders(deviceContext);
	material->BindTexture(deviceContext);
	material->BindSamplerState(deviceContext);
	// 메시 버퍼 그리기.
	mesh->RenderBuffers(deviceContext);

	// 월드 행렬 업데이트.
	mesh2->Update(deviceContext);

	material2->BindShaders(deviceContext);
	material2->BindTexture(deviceContext);
	material2->BindSamplerState(deviceContext);

	// 메시 버퍼 그리기.
	//mesh2->RenderBuffers(deviceContext);

	// 백버퍼 <-> 프론트 버퍼 교환.
	swapChain->Present(1, 0);
}

bool Engine::InitializeScene()
{
	//// 정점 셰이더 생성.
	//vertexShader = new VertexShader(TEXT("Shader//Toon"));
	//// 정점 셰이더 컴파일.
	//if (vertexShader->CompileShader(device) == false)
	//	return false;

	//// 정점 셰이더 객체 생성.
	//if (vertexShader->CreateShader(device) == false)
	//	return false;

	//// 픽셀 셰이더 생성.
	//pixelShader = new PixelShader(TEXT("Shader//Toon"));

	//// 픽셀 셰이더 컴파일.
	//if (material->GetPixelShader()->CompileShader(device) == false)
	//	return false;

	//// 픽셀 셰이더 객체 생성.
	//if (pixelShader->CreateShader(device) == false)
	//	return false;

	//// 텍스처 로드.
	////if (pixelShader->LoadTexture(
	////	device,
	////	TEXT("Resources/Textures/T_Chr_FPS_D.png"))
	////	== false)
	////{
	////	return false;
	////}

	//// 샘플러 스테이트 생성.
	//if (pixelShader->CreateSamplerState(device) == false)
	//	return false;

	//머티리얼 객체 생성
	material = new Material(TEXT("Shader//Toon"));
	material2 = new Material(TEXT("Shader//Specular"));
	
	//각 셰이더 객체 생성
	if (material->CompileShaders(device) == false)
	{
		return false;
	}
	if (material2->CompileShaders(device) == false)
	{
		return false;
	}
	//머터리얼 컴파일
	if (material->CreateShaders(device) == false)
	{
		return false;
	}
	if (material2->CreateShaders(device) == false)
	{
		return false;
	}
	//텍스쳐 관련
	//텍스쳐 추가
	material->AddTexture(TEXT("Resources/Textures/T_Chr_FPS_D.png"));
	material2->AddTexture(TEXT("Resources/Textures/orange.png"));
	//텍스쳐 로드
	if (material->LoadTexture(device) == false)
	{
		return false;
	}
	if (material2->LoadTexture(device) == false)
	{
		return false;
	}
	//샘플러 스테이트 설정
	if (material->CreateSamplerState(device) == false)
	{
		return false;
	}
	if (material2->CreateSamplerState(device) == false)
	{
		return false;
	}

	// 메쉬 생성.
	//mesh = new Mesh(0.0f, 0.0f, 0.0f);
	mesh = new Mesh("Resources/Models/HeroTPP.FBX");
	mesh->SetPosition(0.0f, -90.0f, 0.0f);
	mesh->SetRotation(-90.0f, 180.0f, 0.0f);
	// 초기화.
	if (mesh->InitializeBuffers(device, material) 
		== false)
		return false;

	mesh2 = new Mesh("Resources/Models/SK_CharM_Cardboard.FBX");
	mesh2->SetPosition(-100.0f, -90.0f, 0.0f);
	mesh2->SetRotation(-90.0f, 180.0f, 0.0f);
	// 초기화.
	if (mesh2->InitializeBuffers(device, material2)
		== false)
		return false;

	return true;
}

bool Engine::InitializeTransformation()
{
	// 투영 행렬.
	// 시야각 / 종횡비 설정.
	float fovY = XMConvertToRadians(70.0f);
	float aspectRatio = static_cast<float>(window->GetScreenWidth()) / static_cast<float>(window->GetScreenHeight());
	
	// 카메라 정보 설정.
	pCamera = new Camera(fovY, aspectRatio, 1.0f, 10000.0f);

	// 버퍼에 담을 구조체 변수 설정.
	PerSceneBuffer matrixData;
	matrixData.viewProjection = XMMatrixTranspose(pCamera->GetViewMatrix() * pCamera->GetProjMatrix());
	matrixData.worldLightPosition = XMFLOAT3(500.0f, 500.0f, -500.0f);
	matrixData.worldCameraPosition = pCamera->GetPosition(); // ( 0, 0 , -200)

	// 버퍼 생성.
	// 버퍼 서술자.
	D3D11_BUFFER_DESC cbDesc;
	ZeroMemory(&cbDesc, sizeof(D3D11_BUFFER_DESC));

	cbDesc.ByteWidth = sizeof(PerSceneBuffer);
	cbDesc.CPUAccessFlags = 0;
	cbDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cbDesc.MiscFlags = 0;
	cbDesc.Usage = D3D11_USAGE_DEFAULT;

	// 인덱스 배열 정보 넣어줄 구조체.
	D3D11_SUBRESOURCE_DATA cbData;
	ZeroMemory(&cbData, sizeof(D3D11_SUBRESOURCE_DATA));
	cbData.pSysMem = &matrixData;

	// 상수 버퍼 생성.
	HRESULT result = device->CreateBuffer(&cbDesc, &cbData, &constantBuffer);
	if (IsError(result, TEXT("씬 상수 버퍼 생성 실패")))
	{
		return false;
	}

	return true;
}