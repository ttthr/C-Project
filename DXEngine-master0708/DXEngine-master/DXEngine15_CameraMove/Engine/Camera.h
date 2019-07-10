#pragma once
#include "DXUtil.h"
using namespace std;
using namespace DirectX;

class Camera : public AlinedAllocation<16>
{
public:
	Camera();
	Camera(float fovY, float AspectRatio, float nearZ, float farZ);
	~Camera();
private:  
	XMMATRIX view;                  // �����
	XMMATRIX proj;                  // �������� ���
	XMVECTOR cameraPosition;		// ī�޶� ��ġ.
	XMVECTOR cameraView;			// ī�޶� ����.
	XMVECTOR camerUpVector;			// ī�޶� �� ����.
	float    fovY;                  // �þ߰�
	float    AspectRatio;           // ��Ⱦ��
	float    nearZ;                 // ����
	float    farZ;                  // ��
	float    yaw = 0.0f;
	float    pitch = 0.0f;
	float    roll;
	//New
	//�ٲ� ��
	XMVECTOR cameraUp = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	XMVECTOR cameraRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR cameraFoward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);

	//�⺻ ��
	XMVECTOR defaultcameraUp = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	XMVECTOR defaultcameraRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR defaultcameraFoward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
public:
	void UpdateViewMatrix();
	void UpdateProjMatrix();
public:
	XMMATRIX GetViewMatrix() const { return view; }
	XMMATRIX GetProjMatrix() const { return proj; }
	float GetFovY() const { return fovY; }
	float GetAspectRatio() const { return AspectRatio; }
	XMVECTOR GetPositionVector() const { return cameraPosition; }
	XMFLOAT3 GetPosition() const;

public:
	void SetAspectRatio(UINT width, UINT height);
	//New
	void SetPosition(float x, float y, float z);
	//ī�޶� �̵����� �Լ�
	//�ι��� Ű�׸�ƽ�� Z���� Up��ǥ�̴�.
	void MoveForward(float direction);
	void MoveRight(float direction);
	void MoveUp(float direction);
	void Yaw(float angle);
	void Pitch(float angle);
	void Roll(float angle);
	void UpdateCamera();

};

