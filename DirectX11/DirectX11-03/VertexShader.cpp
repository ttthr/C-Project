#include "VertexShader.h"


VertexShader::VertexShader()
{

}
VertexShader::VertexShader(LPCTSTR fileName)
	:Shader(fileName)
{
	profile = "vs_5_0";
}
VertexShader::VertexShader(LPCTSTR fileName, LPCSTR entryPoint, LPCSTR profile)
	:Shader(fileName, entryPoint, profile)
{


}
VertexShader::~VertexShader()
{


}

bool VertexShader::CompileShader(ID3D11Device * pDevice)
{
	// ���� ���̴� ������ ->����Ʈ �ڵ�
	// ID3D11Blob* debugbuf;
	HRESULT hResult;
	hResult = D3DCompileFromFile(fileName, NULL, NULL, entryPoint, profile, NULL, NULL, &ShaderBuffer, NULL);
	
	if (IsError(hResult, TEXT("���� ���̴� ������ ����")))
	{
		return false;
	}

	return true;
}

bool VertexShader::CreateShader(ID3D11Device * pDevice)
{
	//���� ���̴� ��ü ����
	HRESULT hResult;
	hResult = pDevice->CreateVertexShader(ShaderBuffer->GetBufferPointer(), ShaderBuffer->GetBufferSize(),
		NULL, &pVertexShader);

	if (IsError(hResult, TEXT("���ؽ� ���̴� ���� ����")))
	{
		return false;
	}

	return true;
}

bool VertexShader::BindShader(ID3D11DeviceContext * pDeviceContext)
{
	//���� 
	pDeviceContext->VSSetShader(pVertexShader, NULL, NULL);

	return true;
}

void VertexShader::Release()
{
	Shader::Release();
	if (pVertexShader) { pVertexShader->Release(); }
}
