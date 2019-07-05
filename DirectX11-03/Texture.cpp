#include "Texture.h"

Texture::Texture()
{


}

Texture::~Texture()
{


}

HRESULT Texture::GetScratchImage(LPCTSTR fileName, ScratchImage * Image)
{
	//그림 파일 확장자
	TCHAR fileExtension[10];
	_wsplitpath_s(fileName, NULL, NULL, NULL, NULL, NULL, NULL, fileExtension,
		sizeof(fileExtension) / sizeof(LPCTSTR));

	//이미지 파일 확장자 확인
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
	// 이미지 파일 읽기 -> 텍스쳐 리소스 만들기
	// 텍스쳐 리소스에 이미지 데이터 쓰기
	// 텍스쳐 리소스 뷰 생성하기
	ScratchImage Image;
	HRESULT hResult;
	//이미지 파일로 부터 스크래치 이미지 만들기
	hResult = GetScratchImage(this->fileName, &Image);
	if (IsError(hResult, TEXT("이미지 로드 실패")))
	{
		return false;
	}

	ID3D11Texture2D* Texture;
	hResult = CreateTexture(pDevice, Image.GetImages(),
		Image.GetImageCount(), Image.GetMetadata(), (ID3D11Resource**)&Texture);

	if (IsError(hResult, TEXT("텍스쳐 리소스 생성 실패")))
	{
		return false;
	}

	//셰이더 리소스 뷰 생성
	D3D11_SHADER_RESOURCE_VIEW_DESC ViewDesc;
	ZeroMemory(&ViewDesc, sizeof(D3D11_SHADER_RESOURCE_VIEW_DESC));

	D3D11_TEXTURE2D_DESC Texture2DDesc;
	Texture->GetDesc(&Texture2DDesc);
	ViewDesc.Format = Texture2DDesc.Format;
	ViewDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	ViewDesc.Texture2D.MostDetailedMip = 0; //설정 ㄴㄴ
	ViewDesc.Texture2D.MipLevels = 1;

	hResult = pDevice->CreateShaderResourceView(Texture, &ViewDesc, &TextureResourceView);
	
	if (IsError(hResult, TEXT("셰이더 리소스 뷰 생성 실패")))
	{
		return false;
	}
	// 뷰 만들고 해제
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
