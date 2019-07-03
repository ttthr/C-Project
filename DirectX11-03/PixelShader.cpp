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
}
