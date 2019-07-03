#pragma once
#include "Shader.h"
class PixelShader :
	public Shader
{
public:
	PixelShader();
	PixelShader(LPCTSTR fileName);
	PixelShader(LPCTSTR fileName, LPCSTR entryPoint, LPCSTR profile);
	~PixelShader();
private:
	//ÇÈ¼¿ ¼ÎÀÌ´õ °´Ã¼ ( ¼ø¼ö°¡»óÇÔ¼ö )
	ID3D11PixelShader* pPixelShader;
public:
	virtual bool CompileShader(ID3D11Device* pDevice)override;
	virtual bool CreateShader(ID3D11Device* pDevice)override;
	virtual bool BindShader(ID3D11DeviceContext* pDeviceContext)override;
	virtual void Release()override;
public:
	ID3D11PixelShader* GetPixelShader()const { return pPixelShader; }
};

