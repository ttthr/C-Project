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

