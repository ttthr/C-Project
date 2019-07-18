#include "Engine.h"

Engine::Engine(HINSTANCE hinstance) : DXApp(hinstance)
{

}

Engine::~Engine()
{
	for (auto mesh = meshes.begin(); mesh != meshes.end(); ++mesh)
	{
		Memory::SafeDelete((*mesh));
	}
	Memory::SafeDelete(camera);
	Memory::SafeRelease(constantBuffer);
	Memory::SafeDelete(gameTimer);
	/*renderToTexture->Release();
	Memory::SafeDelete(renderToTexture);
	rtRenderer->Release();
	Memory::SafeDelete(rtRenderer);
	rtMaterial->Release();
	Memory::SafeDelete(rtMaterial);*/

}

int Engine::Run()
{
	return window->Run(this);
}

bool Engine::Init()
{
	if (DXApp::Init() == false)
		return false;

	//타이머 초기화
	InitializeTimer();

	// 입력 초기화.
	InitializeInput();


	// 장면 초기화.
	if (InitializeScene() == false)
		return false;

	// 행렬 초기화.
	if (InitializeTransformation() == false)
		return false;



	return true;
}

void Engine::Update(float deltaTime)
{
	// 월드 행렬 바인딩.
	//mesh->Update(deviceContext);
	/*camera->UpdateCamera();

	PerSceneBuffer matrixData;
	matrixData.viewProjection = XMMatrixTranspose(
		camera->GetViewMatrix() * camera->GetProjectionMatrix()
	);
	matrixData.worldLightPosition = XMFLOAT3(5000.0f, 5000.0f, -5000.0f);
	matrixData.worldCameraPosition = camera->GetPosition();

	deviceContext->UpdateSubresource(constantBuffer, 0, NULL, &matrixData, 0, 0);*/


	// 뷰/투영 행렬 바인딩.
	deviceContext->VSSetConstantBuffers(1, 1, &constantBuffer);
}

void Engine::Render(float deltaTime)
{
	//랜더 투 텍스쳐
	//카메라 업데이트
	UpdatePerspectiveCamera();
	RenderToTextureRender();

	float color[] = { 0.0f, 0.0f, 1.0f, 1.0f };
	//렌더타겟 색상칠하기
	//뎁스/스텐실 뷰 지우기
	BeginScene(color);

	//다시 그리기 ( 백버퍼)
	RenderScene();

	//직교모드 카메라로 설정 변경
	UpdateOrthographicCamera();

	rtMaterial->BindShaders(deviceContext);
	rtMaterial->RTBindTexture(deviceContext, renderToTexture->GetRenderTargetShaderResoureView());
	rtMaterial->BindSamplerState(deviceContext);
	rtRenderer->UpdateBuffers(deviceContext, 100, 100);
	rtRenderer->RenderBuffers(deviceContext);

	//


	//UpdatePerspectiveCamera2();
	//RenderToTextureRender();
	//BeginScene(color);
	
	////다시 그리기 ( 백버퍼)
	//RenderScene();

	//UpdateOrthographicCamera2();

	//rtMaterial2->BindShaders(deviceContext);
	//rtMaterial2->RTBindTexture2(deviceContext, renderToTexture2->GetRenderTargetShaderResoureView());
	//rtMaterial2->BindSamplerState(deviceContext);
	rtRenderer2->UpdateBuffers(deviceContext, 900, 100);
	rtRenderer2->RenderBuffers(deviceContext);


	//// 렌더 타겟을 설정한 색상으로 칠하기.
	//deviceContext->ClearRenderTargetView(renderTargetView, color);

	//// 뎁스/스텐실 뷰 지우기.
	//deviceContext->ClearDepthStencilView(depthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

	// 월드 행렬 바인딩.
	//for (auto iter = meshes.begin(); iter != meshes.end(); ++iter)
	//{

	//	(*iter)->Update(deviceContext);
	//	(*iter)->BindShaders(deviceContext);
	//	(*iter)->BindTextures(deviceContext);
	//	(*iter)->BindSamplerState(deviceContext);
	//	(*iter)->BindRasterizerState(deviceContext);

	//    /*if (input->IsKeyDown(Keyboard::Keys::R))
	//	{
	//		(*iter)->IsOn = true;
	//	}
	//	else if (input->IsKeyDown(Keyboard::Keys::T) && (*iter)->IsOn == true)
	//	{
	//
	//		(*iter)->BindRasterizerState(NULL);
	//		(*iter)->IsOn = false;
	//	}*/
	//	// 메시 버퍼 그리기.

	//	(*iter)->RenderBuffers(deviceContext);

	//}

	// 백버퍼 <-> 프론트 버퍼 교환.
	swapChain->Present(1, 0);
}

void Engine::ProcessInput(float deltaTime)
{
	// ESC 종료 처리.
	if (input->IsKeyDown(Keyboard::Keys::Escape))
	{
		if (MessageBox(NULL, 
			TEXT("종료하시겠습니까?"), 
			TEXT("종료"),
			MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			DestroyWindow(window->GetWindowHandle());
		}
	}

	// 카메라 이동/회전.
	if (input->IsKeyDown(Keyboard::Keys::A) || input->IsKeyDown(Keyboard::Keys::Left))
	{
		camera->MoveRight(-1.0f * camera->GetSpeed() * deltaTime);
	}

	if (input->IsKeyDown(Keyboard::Keys::D) || input->IsKeyDown(Keyboard::Keys::Right))
	{
		camera->MoveRight(1.0f * camera->GetSpeed() *deltaTime);
	}

	if (input->IsKeyDown(Keyboard::Keys::W) || input->IsKeyDown(Keyboard::Keys::Up))
	{
		camera->MoveForward(1.0f * camera->GetSpeed() * deltaTime);
	}

	if (input->IsKeyDown(Keyboard::Keys::S) || input->IsKeyDown(Keyboard::Keys::Down))
	{
		camera->MoveForward(-1.0f * camera->GetSpeed() * deltaTime);
	}

	if (input->IsKeyDown(Keyboard::Keys::Q))
	{
		camera->MoveUp(1.0f * camera->GetSpeed() * deltaTime);
	}

	if (input->IsKeyDown(Keyboard::Keys::E))
	{
		camera->MoveUp(-1.0f * camera->GetSpeed() * deltaTime);
	}

	// 마우스 왼쪽 버튼 눌릴 때만 이동.
	Mouse::State state = input->GetMouseState();
	if (state.leftButton)
	{	
		camera->Yaw(state.x * camera->GetMouseSpeed() * deltaTime);
		camera->Pitch(state.y * camera->GetMouseSpeed()  * deltaTime);
	}

}

bool Engine::InitializeScene()
{
	// FBX 이름 변수
	LPCSTR fbxTPP = "Resources/Models/HeroTPP.FBX";
	LPCSTR fbxCardboard = "Resources/Models/SK_CharM_Cardboard.FBX";
	LPCSTR fbxCube = "Resources/Models/cube.FBX";
	LPCSTR fbxSphere = "Resources/Models/sphere.FBX";
	LPCSTR fbxWarrior = "Resources/Models/SK_CharM_Warrior.FBX";
	LPCSTR fbxBarbarous = "Resources/Models/SK_CharM_Barbarous.FBX";
	LPCSTR fbxBear = "Resources/Models/Enemy_Bear.FBX";

	//텍스쳐 이름 변수
	LPCTSTR DiffuseTPP = (TEXT("Resources/Textures/T_Chr_FPS_D.png"));
	LPCTSTR NormalTPP = (TEXT("Resources/Textures/T_Chr_FPS_N.png"));
	LPCTSTR DiffuseCardboard = (TEXT("Resources/Textures/Char_M_Cardboard_D.png"));
	LPCTSTR NormalCardboard = (TEXT("Resources/Textures/Char_M_Cardboard_N.png"));
	LPCTSTR LightStep = (TEXT("Resources/Textures/LightStep.png"));
	LPCTSTR Warp = (TEXT("Resources/Textures/Warp.png"));
	LPCTSTR DiffuseWarrior = (TEXT("Resources/Textures/T_CharM_Warrior_D.TGA"));
	LPCTSTR NormalWarrior = (TEXT("Resources/Textures/T_CharM_Warrior_N.TGA"));
	LPCTSTR DiffuseBarbarous = (TEXT("Resources/Textures/T_Barbarous_D.TGA"));
	LPCTSTR NormalBarbarous = (TEXT("Resources/Textures/T_Barbarous_N.TGA"));
	LPCTSTR DiffuseBear = (TEXT("Resources/Textures/T_Enemy_Bear_D.TGA"));
	LPCTSTR NormalBear = (TEXT("Resources/Textures/T_Enemy_Bear_N.TGA"));
	LPCTSTR CubeTexture = (TEXT("Resources/Textures/BitchCubeMap.DDS"));

	//셰이더 네임
	LPCTSTR NormalMapping1 = TEXT("Shader/NormalMapping");
	LPCTSTR NormalMapping2 = TEXT("Shader/NormalMapping2");
	LPCTSTR CubeMapping = TEXT("Shader/Cube");
	LPCTSTR RimMapping = TEXT("Shader/LimLighting");
	LPCTSTR OranNayerMapping = TEXT("Shader/OranNayer");

	// 메쉬 생성. 
	// 벡터로 생성

	Mesh* mesh1 = new Mesh(fbxTPP, NormalMapping1);
	mesh1->SetPosition(-70.0f, -90.0f, 0.0f);
	mesh1->SetRotation(-90.0f, 180.0f, 0.0f);
	mesh1->AddTexture(DiffuseTPP);
	mesh1->AddTexture(NormalTPP);

	meshes.push_back(mesh1);

	Mesh* mesh2 = new Mesh(fbxTPP, NormalMapping2);
	mesh2->SetPosition(70.0f, -90.0f, 0.0f);
	mesh2->SetRotation(-90.0f, 180.0f, 0.0f);
	mesh2->AddTexture(DiffuseTPP);
	mesh2->AddTexture(NormalTPP);

	meshes.push_back(mesh2);


	Mesh* mesh3 = new Mesh(fbxWarrior, NormalMapping1);
	mesh3->SetPosition(200.0f, -90.0f, 0.0f);
	mesh3->SetRotation(-90.0f, 180.0f, 0.0f);
	mesh3->AddTexture(DiffuseWarrior);
	mesh3->AddTexture(NormalWarrior);

	meshes.push_back(mesh3);

	Mesh* mesh4 = new Mesh(fbxBarbarous, NormalMapping2);
	mesh4->SetPosition(-200.0f, -90.0f, 0.0f);
	mesh4->SetRotation(-90.0f, 180.0f, 0.0f);
	mesh4->AddTexture(DiffuseBarbarous);
	mesh4->AddTexture(NormalBarbarous);

	meshes.push_back(mesh4);

	Mesh* mesh5 = new Mesh(fbxBear, RimMapping, D3D11_FILL_WIREFRAME, D3D11_CULL_BACK);
	mesh5->SetPosition(-360.0f, -90.0f, 0.0f);
	mesh5->SetRotation(-90.0f, 180.0f, 0.0f);
	mesh5->AddTexture(DiffuseBear);
	mesh5->AddTexture(NormalBear);

	meshes.push_back(mesh5);

	//Mesh* mesh6 = new Mesh(fbxCube, CubeMapping ,D3D11_FILL_SOLID, D3D11_CULL_NONE);
	//mesh6->SetScale(10000.f, 10000.f, 10000.f);
	//mesh6->SetPosition(0.0f, 0.0f, 0.0f);
	//
	//mesh6->AddTexture(CubeTexture);

	//meshes.push_back(mesh6);


	Mesh* mesh7 = new Mesh(fbxBear, OranNayerMapping);
	mesh7->SetPosition(-600.0f, -90.0f, 0.0f);
	mesh7->SetRotation(-90.0f, 180.0f, 0.0f);

	mesh7->AddTexture(DiffuseBear);

	meshes.push_back(mesh7);

	//메쉬 초기화
	if (InitializeMeshs() == false)
		return false;

	//머터리얼 초기화
	rtMaterial = new Material(TEXT("Shader/"));
	//컴파일
	if (rtMaterial->CompileShaders(device) == false)
	{
		return false;
	}
	//셰이더 객체 생성
	if (rtMaterial->CreateShaders(device) == false)
	{
		return false;
	}
	//샘플러 스테이트 설정
	if (rtMaterial->CreateSamplerState(device) == false)
	{
		return false;
	}

	//머터리얼 초기화
	rtMaterial2 = new Material(TEXT("Shader/"));
	//컴파일
	if (rtMaterial2->CompileShaders(device) == false)
	{
		return false;
	}
	//셰이더 객체 생성
	if (rtMaterial2->CreateShaders(device) == false)
	{
		return false;
	}
	//샘플러 스테이트 설정
	if (rtMaterial2->CreateSamplerState(device) == false)
	{
		return false;
	}
	
	
	return true;

}

bool Engine::InitializeTransformation()
{
	// 시야각 / 종횡비 설정.
	float fovY = XMConvertToRadians(60.0f);
	float aspectRatio = static_cast<float>(window->GetScreenWidth()) / static_cast<float>(window->GetScreenHeight());

	// 카메라 객체 생성.
	camera = new Camera(fovY, aspectRatio, 1.0f, 100000.0f);

	// 버퍼에 담을 구조체 변수 설정.
	PerSceneBuffer matrixData;
	matrixData.viewProjection = XMMatrixTranspose(
		camera->GetViewMatrix() * camera->GetProjectionMatrix()
	);
	matrixData.worldLightPosition = XMFLOAT3(500.0f, 500.0f, -500.0f);
	matrixData.worldCameraPosition = camera->GetPosition();

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

	//RenderToTexture 초기화
	renderToTexture = new RenderToTexture();
	if (renderToTexture->Initialize(device, camera, window->GetScreenWidth(), window->GetScreenHeight()) == false)
	{
		return false;
	}
	// RTRenderer 초기화
	rtRenderer = new RTRenderer();
	if (rtRenderer->Initiailze(device, rtMaterial->GetVertexShader()->GetShaderBuffer(), window->GetScreenWidth(), window->GetScreenHeight(), 480, 270) == false)
	{
		return false;
	}

	//RenderToTexture2 초기화
	renderToTexture2 = new RenderToTexture();
	if (renderToTexture2->Initialize(device, camera, window->GetScreenWidth(), window->GetScreenHeight()) == false)
	{
		return false;
	}
	// RTRenderer2 초기화
	rtRenderer2 = new RTRenderer();
	if (rtRenderer2->Initiailze(device, rtMaterial->GetVertexShader()->GetShaderBuffer(), window->GetScreenWidth(), window->GetScreenHeight(), 480, 270) == false)
	{
		return false;
	}


	return true;
}

void Engine::InitializeInput()
{
	input = new InputClass();
	input->InitializeInput(window->GetWindowHandle());
}

void Engine::InitializeTimer()
{
	gameTimer = new GameTimer;
	gameTimer->StartTimer();

}

bool Engine::InitializeMeshs()
{
	for (auto iter = meshes.begin(); iter != meshes.end(); ++iter)
	{
		// 머티리얼 컴파일.
		if ((*iter)->CompileShaders(device) == false)
			return false;
		// 각 셰이더 객체 생성.
		if ((*iter)->CreateShaders(device) == false)
			return false;
		// 텍스처 로드.
		if ((*iter)->LoadTextures(device) == false)
			return false;
		// 샘플러 스테이트 생성.
		if ((*iter)->CreateSamplerState(device) == false)
			return false;
		if ((*iter)->InitializeBuffers(device) == false)
			return false;
		//레스터 라이저 스테이트 생성
		if ((*iter)->CreateRasterizerState(device) == false)
			return false;
	}

	return true;
}

void Engine::RenderToTextureRender()
{
	float color2[] = { 0.0f, 0.7f, 0.7f, 1.0f };
	//렌더 타겟을 바꾼다.
	renderToTexture->SetRenderTarget(deviceContext, depthStencilView);
	renderToTexture->ClearRenderTarget(deviceContext, depthStencilView, color2);

	//씬그리기 
	RenderScene();

	//랜더 타겟 돌려놓기
	deviceContext->OMSetRenderTargets(1, &renderTargetView, depthStencilView);

}

void Engine::RenderScene()
{
	for (auto iter = meshes.begin(); iter != meshes.end(); ++iter)
	{

		(*iter)->Update(deviceContext);
		(*iter)->BindShaders(deviceContext);
		(*iter)->BindTextures(deviceContext);
		(*iter)->BindSamplerState(deviceContext);
		(*iter)->BindRasterizerState(deviceContext);
		(*iter)->RenderBuffers(deviceContext);

	}
}

void Engine::BeginScene(float color[])
{

	// 렌더 타겟을 설정한 색상으로 칠하기.
	deviceContext->ClearRenderTargetView(renderTargetView, color);

	// 뎁스/스텐실 뷰 지우기.
	deviceContext->ClearDepthStencilView(depthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
}

void Engine::UpdatePerspectiveCamera()
{
	camera->UpdateCamera();

	PerSceneBuffer matrixData;
	matrixData.viewProjection = XMMatrixTranspose(
		camera->GetViewMatrix() * camera->GetProjectionMatrix()
	);
	matrixData.worldLightPosition = XMFLOAT3(5000.0f, 5000.0f, -5000.0f);
	matrixData.worldCameraPosition = camera->GetPosition();

	deviceContext->UpdateSubresource(constantBuffer, 0, NULL, &matrixData, 0, 0);
}

void Engine::UpdateOrthographicCamera()
{
	camera->UpdateCamera();

	//바뀐점
	PerSceneBuffer matrixData;
	matrixData.viewProjection = XMMatrixTranspose(
		camera->GetViewMatrix() * renderToTexture->GetProjectionMatrix()
	);
	matrixData.worldLightPosition = XMFLOAT3(5000.0f, 5000.0f, -5000.0f);
	matrixData.worldCameraPosition = camera->GetPosition();

	deviceContext->UpdateSubresource(constantBuffer, 0, NULL, &matrixData, 0, 0);


}

void Engine::UpdatePerspectiveCamera2()
{
	camera->UpdateCamera();

	PerSceneBuffer matrixData;
	matrixData.viewProjection = XMMatrixTranspose(
		camera->GetViewMatrix() * camera->GetProjectionMatrix()
	);
	matrixData.worldLightPosition = XMFLOAT3(5000.0f, 5000.0f, -5000.0f);
	matrixData.worldCameraPosition = camera->GetPosition();

	deviceContext->UpdateSubresource(constantBuffer, 0, NULL, &matrixData, 0, 0);
}

void Engine::UpdateOrthographicCamera2()
{
	camera->UpdateCamera();

	//바뀐점
	PerSceneBuffer matrixData;
	matrixData.viewProjection = XMMatrixTranspose(
		camera->GetViewMatrix() * renderToTexture2->GetProjectionMatrix()
	);
	matrixData.worldLightPosition = XMFLOAT3(5000.0f, 5000.0f, -5000.0f);
	matrixData.worldCameraPosition = camera->GetPosition();

	deviceContext->UpdateSubresource(constantBuffer, 0, NULL, &matrixData, 0, 0);


}
