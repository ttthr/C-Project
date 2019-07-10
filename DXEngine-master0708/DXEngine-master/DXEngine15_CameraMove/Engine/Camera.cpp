#include "Camera.h"



Camera::Camera()
{



}
Camera::Camera(float fovY, float AspectRatio, float nearZ, float farZ)
{
	//초기값 셋팅
	cameraPosition = XMVectorSet(0.0f, 0.0f, -200.0f, 0.0f);
	cameraView = XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
	camerUpVector = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

	this->fovY = fovY;
	this->AspectRatio = AspectRatio;
	this->nearZ = nearZ;
	this->farZ = farZ;

	UpdateViewMatrix();
	UpdateProjMatrix();

}
Camera::~Camera()
{


}
void Camera::UpdateViewMatrix()
{
	view = XMMatrixLookAtLH(cameraPosition, cameraView, camerUpVector);

}
void Camera::UpdateProjMatrix()
{
	proj = XMMatrixPerspectiveFovLH(fovY, AspectRatio, nearZ, farZ);
}

XMFLOAT3 Camera::GetPosition() const
{
	float x = XMVectorGetX(cameraPosition);
	float y = XMVectorGetY(cameraPosition);
	float z = XMVectorGetZ(cameraPosition);
	
	return XMFLOAT3(x, y, z);
}

void Camera::SetAspectRatio(UINT width, UINT height)
{
	AspectRatio = static_cast<float>(width) / static_cast<float>(height);
}

void Camera::SetPosition(float x, float y, float z)
{
	//w좌표에서  1 : 점 , 0 : 벡터
	cameraPosition = XMVectorSet(x, y, z, 1.0f);
	UpdateViewMatrix();
}
void Camera::MoveForward(float direction)
{
	cameraPosition += direction * cameraFoward;

}

void Camera::MoveRight(float direction)
{
	cameraPosition += direction * cameraRight;
}

void Camera::MoveUp(float direction)
{
	cameraPosition += direction * cameraUp;
}

//입력은 각도
void Camera::Yaw(float angle)
{
	yaw += XMConvertToRadians(angle);
}

void Camera::Pitch(float angle)
{
	pitch += XMConvertToRadians(angle);
}

void Camera::Roll(float angle)
{
	roll += XMConvertToRadians(angle);
}

void Camera::UpdateCamera()
{
	XMMATRIX rotationMatrix = XMMatrixRotationRollPitchYaw(pitch, yaw, roll);
	//월드의 앞 방향 벡터를 위에서 구한 회전 행렬만큼 회전시키기
	cameraView = XMVector3TransformCoord(defaultcameraFoward, rotationMatrix);
	//노멀라이즈
	cameraView = XMVector3Normalize(cameraView);
	//Y 회전 값 저장
	XMMATRIX rotationYTemp = XMMatrixRotationY(yaw);
	//카메라 벡터 구하기	
	cameraRight = XMVector3TransformCoord(defaultcameraRight, rotationMatrix);
	cameraUp = XMVector3TransformCoord(defaultcameraUp, rotationMatrix);
	cameraFoward = XMVector3TransformCoord(defaultcameraFoward, rotationMatrix);
	//카메라 룩벡터 갱신
	cameraView = cameraPosition + cameraView;
	//뷰 매트릭스 갱신
	UpdateViewMatrix();
	

}
