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
	// ÇÈ¼¿ ¼ÎÀÌ´õ ÄÄÆÄÀÏ -> ¹ÙÀÌÆ® ÄÚµå
	HRESULT hResult;
	hResult = D3DCompileFromFile(fileName, NULL, NULL, entryPoint, profile, NULL, NULL, &ShaderBuffer, NULL);
	
	if (IsError(hResult, TEXT("ÇÈ¼Ð ¼ÎÀÌ´õ ÄÄÆÄÀÏ ¿À·ù")))
	{
		return false;
	}

	return true;
}

bool PixelShader::CreateShader(ID3D11Device * pDevice)
{
	//ÇÈ¼Ð ¼ÎÀÌ´õ °´Ã¼ »ý¼º
	HRESULT hResult;
	hResult = pDevice->CreatePixelShader(ShaderBuffer->GetBufferPointer(), ShaderBuffer->GetBufferSize(),
		NULL,&pPixelShader);

	if (IsError(hResult, TEXT("ÇÈ¼Ð ¼ÎÀÌ´õ »ý¼º ½ÇÆÐ")))
	{
		return false;
	}

	return true;
}

bool PixelShader::BindShader(ID3D11DeviceContext * pDeviceContext)
{
	//ÇÈ¼Ð ¼ÎÀÌ´õ ¿¬°á
	pDeviceContext->PSSetShader(pPixelShader, NULL, NULL);
	return true;
}

void PixelShader::Release()
{
	Shader::Release();
	if (pPixelShader){ pPixelShader->Release();}
}
