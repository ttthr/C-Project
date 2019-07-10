#include "Material.h"

Material::Material(LPCTSTR ShaderName)
{
	this->ShaderName = ShaderName;
	vertexShader = new VertexShader(ShaderName);
	pixelShader = new PixelShader(ShaderName);

}

Material::~Material()
{


}
bool Material::CompileShaders(ID3D11Device * pd3dDevice)
{
	//���� ���̴� ������
	if (vertexShader->CompileShader(pd3dDevice) == false)
	{
		return false;

	}
	//�ȼ� ���̴� ������
	if (pixelShader->CompileShader(pd3dDevice) == false)
	{
		return false;
	}
	return true;
}

bool Material::CreateShaders(ID3D11Device * pd3dDevice)
{
	//���� ���̴� ����
	if (vertexShader->CreateShader(pd3dDevice) == false)
	{
		return false;
	}
	//�ȼ� ���̴� ����
	if (pixelShader->CreateShader(pd3dDevice) == false)
	{
		return false;
	}
	return true;
}

void Material::BindShaders(ID3D11DeviceContext * pd3dDeviceContext)
{
	vertexShader->BindShader(pd3dDeviceContext);
	pixelShader->BindShader(pd3dDeviceContext);	
}

void Material::AddTexture(LPCTSTR fileName)
{
	pixelShader->AddTexture(fileName);
}

bool Material::LoadTexture(ID3D11Device * pd3dDevice)
{
	if (pixelShader->LoadTexture(pd3dDevice) == false)
	{
		return false;
	}
	return true;
}

void Material::BindTexture(ID3D11DeviceContext * pd3dDeviceContext)
{
	pixelShader->BindTexture(pd3dDeviceContext);
}

bool Material::CreateSamplerState(ID3D11Device * pd3dDevice)
{
	if (pixelShader->CreateSamplerState(pd3dDevice) == false)
	{
		return false;
	}
	return true;
}

void Material::BindSamplerState(ID3D11DeviceContext * pd3dDeviceContext)
{
	pixelShader->BindSamplerState(pd3dDeviceContext);
}

void Material::Release()
{
	vertexShader->Release();
	pixelShader->Release();
}

