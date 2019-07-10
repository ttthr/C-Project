#include "Engine.h"


Engine::Engine(HINSTANCE hInstance)
	:DXApp(hInstance)
{


}

Engine::~Engine()
{
	//if (pMesh)
	//{
		//delete pMesh;
		//pMesh = NULL;
	//}
	pVertexShader->Release();
	if (pVertexShader)
	{
		delete pVertexShader;
		pVertexShader = NULL;
	}
	pPixelShader->Release();
	if (pPixelShader)
	{
		delete pPixelShader;
		pPixelShader = NULL;
	}

}

int Engine::Run()
{
	//엔진 루프
	return window->Run(this);
}

bool Engine::Init()
{
	//DX초기화
	if (DXApp::Init() == false)
	{
		return false;
	}
	//장면 초기화
	if (InitializeScene() == false)
	{
		return false;
	}
	// 행렬 초기화
	if (InitializeTransformation() == false)
	{
		return false;
	}
	return true;
}

void Engine::Update()
{
	//월드 행렬 업데이트
	pMesh->Update(m_pd3dDeviceContext);
	// 뷰,투영행렬 상수버퍼로 넘기기
	m_pd3dDeviceContext->VSSetConstantBuffers(1, 1, &ViewProjConstantBuffer);
}

void Engine::Render()
{
	float color[]{ 0.0f, 0.0f, 1.0f , 1.0f };

	//렌더 타겟을 설정한 색상으로 칠하기
	m_pd3dDeviceContext->ClearRenderTargetView(m_pRenderTargetView, color);

	//버텍스, 셰이더 바인딩 할 곳
	pVertexShader->BindShader(m_pd3dDeviceContext);
	pPixelShader->BindShader(m_pd3dDeviceContext);

	//텍스처,샘플러 스테이트 바인딩
	pPixelShader->BindTexture(m_pd3dDeviceContext);
	pPixelShader->BindSamplerState(m_pd3dDeviceContext);
	
	//메쉬 렌더
	pMesh->RenderBuffers(m_pd3dDeviceContext);

	//버퍼 교환
	m_pSwapChain->Present(1, 0);
}

bool Engine::InitializeScene()
{
	//버텍스 셰이더 생성
	pVertexShader = new VertexShader(TEXT("Shader//DiffuseVS.fx"));
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
	pPixelShader = new PixelShader(TEXT("Shader//DiffusePS.fx"));
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
	//텍스쳐 로드

	if (pPixelShader->RoadTexture(m_pd3dDevice, TEXT("Resource/Textures/T_Chr_FPS_N.png")) == false)
	{
		return false;
	}
	//샘플러 스테이트 설정
	if (pPixelShader->CreateSamplerState(m_pd3dDevice) == false)
	{
		return false;
	}

	
	//메쉬 생성
	//pMesh = new Mesh(0.0f, 0.0f, 0.0f);
	pMesh = new Mesh("Resource/Models/HeroTPP.FBX");
	pMesh->SetPosition(0.0f, -90.0f, 0.0f);
	pMesh->SetRotation(-90.0f, 180.0f, 0.0f);

	//초기화
	if (pMesh->InitailizeBuffers(m_pd3dDevice, pVertexShader->GetShaderBuffer()) == false)
	{
		return false;
	}


	return true;

}

bool Engine::InitializeTransformation()
{
	//카메라 정보 셋팅
	CameraPosition = XMVectorSet(0.0f, 0.0f, -200.0f, 0.0f);
	CameraView = XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
	CameraUp = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

	//뷰 행렬 만들기
	XMMATRIX ViewMatrix;
	ViewMatrix = XMMatrixLookAtLH(CameraPosition, CameraView, CameraUp);

	//투영 행렬 
	//시야각 / 종횡비 설정
	float fovY = XMConvertToRadians(70.0f);
	float AspectRatio = static_cast<float>(window->GetscreenWidth()) / static_cast<float>(window->GetscreenHeight());

	XMMATRIX ProjMatrix;
	ProjMatrix = XMMatrixPerspectiveFovLH(fovY, AspectRatio, 1.0f, 10000.0f);

	//상수 버퍼에 담을 구조체 변수 설정
	PerSceneBuffer MatrixData;
	MatrixData.ViewMatrix = XMMatrixTranspose(ViewMatrix);
	MatrixData.ProjMatrix = XMMatrixTranspose(ProjMatrix);

	// View, Proj 상수버퍼 생성
	D3D11_BUFFER_DESC MatrixBufferDesc; //서술자
	ZeroMemory(&MatrixBufferDesc, sizeof(D3D11_BUFFER_DESC)); //초기화
	MatrixBufferDesc.ByteWidth = sizeof(PerSceneBuffer); //바이트 수 계산
	MatrixBufferDesc.CPUAccessFlags = 0; // CPU가 접근못하게 0으로 설정해주면됨
	MatrixBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER; // 버텍스 버퍼 사용
	MatrixBufferDesc.MiscFlags = 0; //버퍼를 다른용도로 만들때 넣는 곳
	MatrixBufferDesc.Usage = D3D11_USAGE_DEFAULT; //CPU가 접근못함 

	//상수 버퍼 정보를 넣어줄 구조체
	D3D11_SUBRESOURCE_DATA MatrixSubResouceVB;
	ZeroMemory(&MatrixSubResouceVB, sizeof(D3D11_SUBRESOURCE_DATA));
	MatrixSubResouceVB.pSysMem = &MatrixData;

	//버퍼 생성
	HRESULT hResult;
	hResult = m_pd3dDevice->CreateBuffer(&MatrixBufferDesc, &MatrixSubResouceVB, &ViewProjConstantBuffer);

	if (FAILED(hResult))
	{
		MessageBox(NULL, TEXT("씬 상수버퍼 생성 실패"), TEXT("오류"), MB_OK);
		return false;
	}
	return true;
}
