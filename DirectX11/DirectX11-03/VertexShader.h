#pragma once
#include "Shader.h"
class VertexShader :
	public Shader
{
public:
	VertexShader();
	VertexShader(LPCTSTR fileName);
	VertexShader(LPCTSTR fileName, LPCSTR entryPoint, LPCSTR profile);
	~VertexShader();
private:
	//�������̴� ��ü ( ���������Լ� )
	ID3D11VertexShader* pVertexShader;
public:
	virtual bool CompileShader(ID3D11Device* pDevice)override;
	virtual bool CreateShader(ID3D11Device* pDevice)override;
	virtual bool BindShader(ID3D11DeviceContext* pDeviceContext)override;
	virtual void Release()override;
public:
	ID3D11VertexShader* GetVertexShader()const { return pVertexShader; }

};

