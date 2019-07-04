#pragma once
#include "DXUtility.h"

// LPCTSTR
// 유니코드 / 멀티바이트 알아서 처리 해줌

class Shader
{
public:
	Shader();
	Shader(LPCTSTR fileName);
	Shader(LPCTSTR fileName, LPCSTR entryPoint, LPCSTR profile);
	virtual ~Shader();
protected:
	LPCTSTR fileName;       // 셰이더 파일이름
	LPCSTR  entryPoint;     // 셰이더 진입 함수 이름 char*
	LPCSTR  profile;        // 셰이더 버전 정보 "vs_4_0"
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

