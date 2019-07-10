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

};

