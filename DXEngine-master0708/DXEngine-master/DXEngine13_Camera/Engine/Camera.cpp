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
