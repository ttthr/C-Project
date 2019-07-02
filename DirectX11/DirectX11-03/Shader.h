#pragma once
#include "DXUtility.h"

class Shader
{
public:
	Shader();
	Shader(LPTSTR fileName);
	Shader(LPTSTR fileName, LPCSTR entry, LPCSTR profile);
	virtual ~Shader();
protected:
	LPCTSTR fileName;       // 셰이더 파일이름
	LPCSTR  entryPoint;     // 셰이더 진입 함수 이름
	LPCSTR  profile;        // 셰이더 버전 정보
    ID3DBlob* ShaderBuffer; // 셰이더 컴파일 결과 저장용 변수
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

