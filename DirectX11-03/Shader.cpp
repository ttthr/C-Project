#include "Shader.h"

Shader::Shader()
{


}
Shader::Shader(LPCTSTR fileName)
{
	
	this->fileName = fileName;
	entryPoint = "main"; // �����Լ�����

}
Shader::Shader(LPCTSTR fileName, LPCSTR entryPoint, LPCSTR profile)
{
	this->fileName = fileName;
	this->entryPoint = entryPoint;
	this->profile = profile;

}
Shader::~Shader()
{

	

}
void Shader::Release()
{
	if (ShaderBuffer){ShaderBuffer->Release();}
}
void Shader::SetFileNmae(LPCTSTR fileName)
{
	this->fileName = fileName;
}
