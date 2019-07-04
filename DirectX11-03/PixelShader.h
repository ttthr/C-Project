#pragma once
#include "Shader.h"
#include "Texture.h"

class Texture;

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
	//2019.07.04
	Texture texture;
	ID3D11SamplerState* SamplerState;
public:
	virtual bool CompileShader(ID3D11Device* pDevice)override;
	virtual bool CreateShader(ID3D11Device* pDevice)override;
	virtual bool BindShader(ID3D11DeviceContext* pDeviceContext)override;
	virtual void Release()override;
public:
	ID3D11PixelShader* GetPixelShader()const { return pPixelShader; }
public:
	//2019.07.04
	Texture GetTexture()const { return texture; }
	ID3D11SamplerState* GetSamplerState() const { return SamplerState; }
	bool RoadTexture(ID3D11Device* pDevice, LPCTSTR fileName);
	void BindTexture(ID3D11DeviceContext* pDeviceContext);
	bool CreateSamplerState(ID3D11Device* pDevice);
	void BindSamplerState(ID3D11DeviceContext* pDeviceContext);
};

