#pragma once
#include "VertexShader.h"
#include "PixelShader.h"

class Material
{
public:
	Material(){}
	Material(LPCTSTR ShaderName);
	~Material();
private:
	LPCTSTR ShaderName;
	VertexShader* vertexShader;
	PixelShader*  pixelShader;
public:
	bool CompileShaders(ID3D11Device* pd3dDevice);
	bool CreateShaders(ID3D11Device* pd3dDevice);
	void BindShaders(ID3D11DeviceContext* pd3dDeviceContext);
	void AddTexture(LPCTSTR fileName);
	bool LoadTexture(ID3D11Device* pd3dDevice);
	void BindTexture(ID3D11DeviceContext* pd3dDeviceContext);
	bool CreateSamplerState(ID3D11Device* pd3dDevice);
	void BindSamplerState(ID3D11DeviceContext* pd3dDeviceContext);
	void Release();
public:
	VertexShader* GetVertexShader() const { return vertexShader; }
	PixelShader* GetPixelShader() const { return pixelShader; }
};

