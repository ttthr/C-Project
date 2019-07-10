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
	XMMATRIX view;                  // 뷰행렬
	XMMATRIX proj;                  // 프로젝션 행렬
	XMVECTOR cameraPosition;		// 카메라 위치.
	XMVECTOR cameraView;			// 카메라 방향.
	XMVECTOR camerUpVector;			// 카메라 위 방향.
	float    fovY;                  // 시야각
	float    AspectRatio;           // 종횡비
	float    nearZ;                 // 가깝
	float    farZ;                  // 멀
	float    yaw = 0.0f;
	float    pitch = 0.0f;
	float    roll;
	//New
	//바뀔 값
	XMVECTOR cameraUp = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	XMVECTOR cameraRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR cameraFoward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);

	//기본 값
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
	//카메라 이동관련 함수
	//인버스 키네마틱스 Z축이 Up좌표이다.
	void MoveForward(float direction);
	void MoveRight(float direction);
	void MoveUp(float direction);
	void Yaw(float angle);
	void Pitch(float angle);
	void Roll(float angle);
	void UpdateCamera();

};

