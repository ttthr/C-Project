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
	// 정점 셰이더 컴파일 ->바이트 코드
	// ID3D11Blob* debugbuf;
	HRESULT hResult;
	hResult = D3DCompileFromFile(fileName, NULL, NULL, entryPoint, profile, NULL, NULL, &ShaderBuffer, NULL);
	
	if (IsError(hResult, TEXT("정점 셰이더 컴파일 오류")))
	{
		return false;
	}

	return true;
}

bool VertexShader::CreateShader(ID3D11Device * pDevice)
{
	//정점 셰이더 객체 생성
	HRESULT hResult;
	hResult = pDevice->CreateVertexShader(ShaderBuffer->GetBufferPointer(), ShaderBuffer->GetBufferSize(),
		NULL, &pVertexShader);

	if (IsError(hResult, TEXT("버텍스 셰이더 생성 실패")))
	{
		return false;
	}

	return true;
}

bool VertexShader::BindShader(ID3D11DeviceContext * pDeviceContext)
{
	//연결 
	pDeviceContext->VSSetShader(pVertexShader, NULL, NULL);

	return true;
}

void VertexShader::Release()
{
	Shader::Release();
	if (pVertexShader) { pVertexShader->Release(); }
}
