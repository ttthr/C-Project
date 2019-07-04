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
	// 픽셀 셰이더 컴파일 -> 바이트 코드
	HRESULT hResult;
	hResult = D3DCompileFromFile(fileName, NULL, NULL, entryPoint, profile, NULL, NULL, &ShaderBuffer, NULL);
	
	if (IsError(hResult, TEXT("픽셸 셰이더 컴파일 오류")))
	{
		return false;
	}

	return true;
}

bool PixelShader::CreateShader(ID3D11Device * pDevice)
{
	//픽셸 셰이더 객체 생성
	HRESULT hResult;
	hResult = pDevice->CreatePixelShader(ShaderBuffer->GetBufferPointer(), ShaderBuffer->GetBufferSize(),
		NULL,&pPixelShader);

	if (IsError(hResult, TEXT("픽셸 셰이더 생성 실패")))
	{
		return false;
	}

	return true;
}

bool PixelShader::BindShader(ID3D11DeviceContext * pDeviceContext)
{
	//픽셸 셰이더 연결
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
	//텍스쳐 로드

	texture.fileName = fileName;
	if (texture.RoadTextureFromFile(pDevice) == false)
	{
		return false;
	}


	return true;
}

void PixelShader::BindTexture(ID3D11DeviceContext * pDeviceContext)
{
	//셰이더 리소스뷰 바인딩
	//텍스쳐 한장 넘기는 거임
	pDeviceContext->PSSetShaderResources(0, 1, &texture.TextureResourceView);
}

bool PixelShader::CreateSamplerState(ID3D11Device * pDevice)
{
	//서술자 생성
	D3D11_SAMPLER_DESC SampleDesc;
	ZeroMemory(&SampleDesc, sizeof(D3D11_SAMPLER_DESC));
	SampleDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	SampleDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	SampleDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	SampleDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	SampleDesc.MinLOD = 0;
	SampleDesc.MaxLOD = D3D11_FLOAT32_MAX;

	//샘플러 스테이트 생성
	HRESULT hResult;
	hResult = pDevice->CreateSamplerState(&SampleDesc, &SamplerState);

	if (IsError(hResult, TEXT("샘플러 스테이트 생성 실패")))
	{
		return false;
	}
	return true;
}

void PixelShader::BindSamplerState(ID3D11DeviceContext * pDeviceContext)
{
	//샘플러 스테이트 바인딩
	pDeviceContext->PSSetSamplers(0, 1, &SamplerState);
}
