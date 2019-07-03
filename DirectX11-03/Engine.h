#pragma once
#include "DXApp.h"
#include "Mesh.h"
#include "VertexShader.h"
#include "PixelShader.h"

class Engine :
	public DXApp
{
public:
	Engine(HINSTANCE hInstance);
	virtual ~Engine();
public:
	virtual int Run()override;;
	virtual bool Init()override;
	virtual void Update() override;
	virtual void Render()override;
private:
	//뷰,프로젝션 행렬
	struct PerSceneBuffer
	{
		PerSceneBuffer()
		{
			ZeroMemory(this, sizeof(this));
		}
		XMMATRIX ViewMatrix;
		XMMATRIX ProjMatrix;
	};
	ID3D11Buffer* ViewProjConstantBuffer;
	//카메라 정보
	XMVECTOR CameraPosition; //카메라 위치
	XMVECTOR CameraView;     //카메라 방향
	XMVECTOR CameraUp;       // 카메라 업 벡터
private:
	VertexShader* pVertexShader;
	PixelShader*  pPixelShader;
	Mesh*         pMesh;
private:
	//장면(Scene) 초기화
	bool InitializeScene();
	bool InitializeTransformation();

};

