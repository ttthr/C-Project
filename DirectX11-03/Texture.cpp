#include "Texture.h"

Texture::Texture()
{


}

Texture::~Texture()
{


}

HRESULT Texture::GetScratchImage(LPCTSTR fileName, ScratchImage * Image)
{
	//�׸� ���� Ȯ����
	TCHAR fileExtension[10];
	_wsplitpath_s(fileName, NULL, NULL, NULL, NULL, NULL, NULL, fileExtension,
		sizeof(fileExtension) / sizeof(LPCTSTR));

	//�̹��� ���� Ȯ���� Ȯ��
	if (wcscmp(fileExtension, TEXT(".tga")) == 0 || wcscmp(fileExtension, TEXT(".TGA")) == 0)
	{
		return LoadFromTGAFile(fileName, NULL, *Image);
	}
	else if (wcscmp(fileExtension, TEXT(".dds")) == 0 || wcscmp(fileExtension, TEXT(".DDS")) == 0)
	{
		return LoadFromDDSFile(fileName, DDS_FLAGS_NONE, NULL, *Image);
	}
	else
	{
		return LoadFromWICFile(fileName, WIC_FLAGS_NONE, NULL, *Image);
	}
}

bool Texture::RoadTextureFromFile(ID3D11Device * pDevice)
{
	// �̹��� ���� �б� -> �ؽ��� ���ҽ� �����
	// �ؽ��� ���ҽ��� �̹��� ������ ����
	// �ؽ��� ���ҽ� �� �����ϱ�
	ScratchImage Image;
	HRESULT hResult;
	//�̹��� ���Ϸ� ���� ��ũ��ġ �̹��� �����
	hResult = GetScratchImage(this->fileName, &Image);
	if (IsError(hResult, TEXT("�̹��� �ε� ����")))
	{
		return false;
	}

	ID3D11Texture2D* Texture;
	hResult = CreateTexture(pDevice, Image.GetImages(),
		Image.GetImageCount(), Image.GetMetadata(), (ID3D11Resource**)&Texture);

	if (IsError(hResult, TEXT("�ؽ��� ���ҽ� ���� ����")))
	{
		return false;
	}

	//���̴� ���ҽ� �� ����
	D3D11_SHADER_RESOURCE_VIEW_DESC ViewDesc;
	ZeroMemory(&ViewDesc, sizeof(D3D11_SHADER_RESOURCE_VIEW_DESC));

	D3D11_TEXTURE2D_DESC Texture2DDesc;
	Texture->GetDesc(&Texture2DDesc);
	ViewDesc.Format = Texture2DDesc.Format;
	ViewDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	ViewDesc.Texture2D.MostDetailedMip = 0; //���� ����
	ViewDesc.Texture2D.MipLevels = 1;

	hResult = pDevice->CreateShaderResourceView(Texture, &ViewDesc, &TextureResourceView);
	
	if (IsError(hResult, TEXT("���̴� ���ҽ� �� ���� ����")))
	{
		return false;
	}
	// �� ����� ����
	if (Texture)
	{ 
		Texture->Release();
	}

	return true;
}

void Texture::Release()
{
	if (TextureResourceView){TextureResourceView->Release();}
}
