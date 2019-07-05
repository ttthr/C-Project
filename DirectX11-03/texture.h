#pragma once
#include "DXUtility.h"
#include "Libary/DirectXTex.h"

#pragma comment(lib, "Libary/DirectXTex.lib")

using namespace DirectX;

//2019.07.04

class Texture
{
public:
	Texture();
	~Texture();
private:
	HRESULT GetScratchImage(LPCTSTR fileName, ScratchImage* Image);
public:
	LPCTSTR fileName;
   ID3D11ShaderResourceView* TextureResourceView;
public:
	bool RoadTextureFromFile(ID3D11Device* pDevice);
	void Release();

};

