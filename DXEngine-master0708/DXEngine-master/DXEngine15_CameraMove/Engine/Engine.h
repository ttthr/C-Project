#pragma once

#include "DXApp.h"
#include "Mesh.h"
#include "Material.h"
#include "Camera.h"
#include "InputClass.h"

class Engine : public DXApp
{
private:
	struct PerSceneBuffer
	{
		PerSceneBuffer() { ZeroMemory(this, sizeof(this)); }

		XMMATRIX viewProjection;
		XMFLOAT3 worldLightPosition;
		XMFLOAT3 worldCameraPosition;
	};

public:
	Engine(HINSTANCE hinstance);
	~Engine();

	int Run();
	bool Init() override;
	void Update() override;
	void Render() override;
	void ProcessInput();

private:

	// ���(Scene) �ʱ�ȭ.
	bool InitializeScene();
	bool InitializeTransformation();
	void InitializeInput();

private:

	Material* material;
	Material* material2; //New

	ID3D11Buffer* constantBuffer;			// ��, ������� ����.

	// ī�޶�
	Camera* pCamera;

	Mesh* mesh;
	Mesh* mesh2; // New

	//�Է�
	InputClass* input;
};