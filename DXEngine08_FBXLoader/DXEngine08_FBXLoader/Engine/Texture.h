#pragma once

#include "DXUtil.h"
#include "../Library/DirectXTex.h"				//��� �����ÿ� ��Ŭ��忡�� �� ���� ���� ����

#pragma comment(lib, "Library/DirectXTex.lib")	//�����׸� �ڸ�Ʈ���� �ش� ��ġ�� ����

using namespace DirectX;

class Texture
{
public:
	Texture();
	~Texture();

	bool LoadTextureFromFile(ID3D11Device* device);
	void Release();

private:

	HRESULT GetScratchImage(LPCTSTR fileName, ScratchImage* image);

public:

	LPCTSTR fileName;		// �̹��� ���� �̸�(Ȯ���� ����).
	ID3D11ShaderResourceView* textureResourceView;	// ���̴� ���ҽ� ��.
};