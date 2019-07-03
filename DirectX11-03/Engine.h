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
	//��,�������� ���
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
	//ī�޶� ����
	XMVECTOR CameraPosition; //ī�޶� ��ġ
	XMVECTOR CameraView;     //ī�޶� ����
	XMVECTOR CameraUp;       // ī�޶� �� ����
private:
	VertexShader* pVertexShader;
	PixelShader*  pPixelShader;
	Mesh*         pMesh;
private:
	//���(Scene) �ʱ�ȭ
	bool InitializeScene();
	bool InitializeTransformation();

};

