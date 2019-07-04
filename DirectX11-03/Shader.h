#pragma once
#include "DXUtility.h"

// LPCTSTR
// �����ڵ� / ��Ƽ����Ʈ �˾Ƽ� ó�� ����

class Shader
{
public:
	Shader();
	Shader(LPCTSTR fileName);
	Shader(LPCTSTR fileName, LPCSTR entryPoint, LPCSTR profile);
	virtual ~Shader();
protected:
	LPCTSTR fileName;       // ���̴� �����̸�
	LPCSTR  entryPoint;     // ���̴� ���� �Լ� �̸� char*
	LPCSTR  profile;        // ���̴� ���� ���� "vs_4_0"
    ID3DBlob* ShaderBuffer; // ���̴� ������ ��� ����� ����
public:
	virtual bool CompileShader(ID3D11Device* pDevice) = 0;
	virtual bool CreateShader(ID3D11Device* pDevice) = 0;
	virtual bool BindShader(ID3D11DeviceContext* pDeviceContext) = 0;
	virtual void Release();
public:
	void SetFileNmae(LPCTSTR fileName);
	LPCTSTR GetFileName()const { return fileName; }
	LPCSTR GetProFile()const { return profile; }
   ID3DBlob* GetShaderBuffer() const { return ShaderBuffer; }

};

