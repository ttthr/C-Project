#include "PixelShader.h"

PixelShader::PixelShader()
{

}

PixelShader::PixelShader(LPCTSTR fileName)
	:Shader(fileName)
{
	profile = "ps_5_0";
}

PixelShader::PixelShader(LPCTSTR fileName, LPCSTR entryPoint, LPCSTR profile)
	:Shader(fileName, entryPoint, profile)
{

}

PixelShader::~PixelShader()
{

}

bool PixelShader::CompileShader(ID3D11Device * pDevice)
{
	// �ȼ� ���̴� ������ -> ����Ʈ �ڵ�
	HRESULT hResult;
	hResult = D3DCompileFromFile(fileName, NULL, NULL, entryPoint, profile, NULL, NULL, &ShaderBuffer, NULL);
	
	if (IsError(hResult, TEXT("�ȼ� ���̴� ������ ����")))
	{
		return false;
	}

	return true;
}

bool PixelShader::CreateShader(ID3D11Device * pDevice)
{
	//�ȼ� ���̴� ��ü ����
	HRESULT hResult;
	hResult = pDevice->CreatePixelShader(ShaderBuffer->GetBufferPointer(), ShaderBuffer->GetBufferSize(),
		NULL,&pPixelShader);

	if (IsError(hResult, TEXT("�ȼ� ���̴� ���� ����")))
	{
		return false;
	}

	return true;
}

bool PixelShader::BindShader(ID3D11DeviceContext * pDeviceContext)
{
	//�ȼ� ���̴� ����
	pDeviceContext->PSSetShader(pPixelShader, NULL, NULL);
	return true;
}

void PixelShader::Release()
{
	Shader::Release();
	if (pPixelShader){ pPixelShader->Release();}
	if (SamplerState) { SamplerState->Release(); }
}

bool PixelShader::RoadTexture(ID3D11Device * pDevice, LPCTSTR fileName)
{
	//�ؽ��� �ε�

	texture.fileName = fileName;
	if (texture.RoadTextureFromFile(pDevice) == false)
	{
		return false;
	}


	return true;
}

void PixelShader::BindTexture(ID3D11DeviceContext * pDeviceContext)
{
	//���̴� ���ҽ��� ���ε�
	//�ؽ��� ���� �ѱ�� ����
	pDeviceContext->PSSetShaderResources(0, 1, &texture.TextureResourceView);
}

bool PixelShader::CreateSamplerState(ID3D11Device * pDevice)
{
	//������ ����
	D3D11_SAMPLER_DESC SampleDesc;
	ZeroMemory(&SampleDesc, sizeof(D3D11_SAMPLER_DESC));
	SampleDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	SampleDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	SampleDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	SampleDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	SampleDesc.MinLOD = 0;
	SampleDesc.MaxLOD = D3D11_FLOAT32_MAX;

	//���÷� ������Ʈ ����
	HRESULT hResult;
	hResult = pDevice->CreateSamplerState(&SampleDesc, &SamplerState);

	if (IsError(hResult, TEXT("���÷� ������Ʈ ���� ����")))
	{
		return false;
	}
	return true;
}

void PixelShader::BindSamplerState(ID3D11DeviceContext * pDeviceContext)
{
	//���÷� ������Ʈ ���ε�
	pDeviceContext->PSSetSamplers(0, 1, &SamplerState);
}
