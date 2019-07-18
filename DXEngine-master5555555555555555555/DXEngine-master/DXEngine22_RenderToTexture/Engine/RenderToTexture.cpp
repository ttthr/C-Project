#include "RenderToTexture.h"



RenderToTexture::RenderToTexture()
{
	RenderTagetTexture2D = NULL;
	RenderTagetView = NULL;
	RenderTargetShaderResoureView = NULL;
}

RenderToTexture::~RenderToTexture()
{


}

bool RenderToTexture::Initialize(ID3D11Device * pd3dDevice, Camera * pCamera, int width, int height)
{
	//¼­¼úÀÚ
	D3D11_TEXTURE2D_DESC desc;
	ZeroMemory(&desc, sizeof(D3D11_TEXTURE2D_DESC));
	desc.Width = width;
	desc.Height = height;
	desc.MipLevels = 1;
	desc.ArraySize = 1; //ÇÑÀå º¸³¾ °Í
	desc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	desc.SampleDesc.Count = 1; //¾ÈÆ¼¾Ë¸®¾Æ½Ì 1ÀÌ¸é ¾ÈÇÏ´Â °Í
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE; // Draw°¡ °É¸®¸é ·»´õÅ¸°ÙÀ» ±×¸®°í / ±×¸®´Â °Å ±îÁö ÇÏ°Ú´Ù´ÂÀÇ¹Ì
	desc.CPUAccessFlags = 0;
	desc.MiscFlags = 0; 

	// RT ÅØ½ºÃÄ »ý¼º
	HRESULT h =  pd3dDevice->CreateTexture2D(&desc, NULL, &RenderTagetTexture2D);

	if (IsError(h, TEXT("RT ·»´õ Å¸°Ù ÅØ½ºÃÄ »ý¼º ½ÇÆÐ")))
	{
		return false;
	}
	//¼­¼úÀÚ
	D3D11_RENDER_TARGET_VIEW_DESC Rtvdesc;
	ZeroMemory(&Rtvdesc, sizeof(D3D11_RENDER_TARGET_VIEW_DESC));
	Rtvdesc.Format = desc.Format;
	Rtvdesc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
	Rtvdesc.Texture2D.MipSlice = 0;

	//RT ·»´õ Å¸°Ù ºä »ý¼º
	h = pd3dDevice->CreateRenderTargetView(RenderTagetTexture2D, &Rtvdesc, &RenderTagetView);

	if (IsError(h, TEXT("RT ·»´õ Å¸°Ù »ý¼º ½ÇÆÐ")))
	{
		return false;
	}

	// ¼ÎÀÌ´õ ¸®¼Ò½º ºä »ý¼º
	D3D11_SHADER_RESOURCE_VIEW_DESC shaderDesc;
	ZeroMemory(&shaderDesc, sizeof(D3D11_SHADER_RESOURCE_VIEW_DESC));
	shaderDesc.Format = desc.Format;
	shaderDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	shaderDesc.Texture2D.MostDetailedMip = 0;
	shaderDesc.Texture2D.MipLevels = 1;

	//RT ¼ÎÀÌ´õ ¸®¼Ò½º ºä »ý¼º
	h = pd3dDevice->CreateShaderResourceView(RenderTagetTexture2D , &shaderDesc, &RenderTargetShaderResoureView);


	if (IsError(h, TEXT("RT ¼ÎÀÌ´õ ¸®¼Ò½º ºä »ý¼º ½ÇÆÐ")))
	{
		return false;
	}

	//ºä/Åõ¿µ Çà·Ä ¸¸µé±â
	view = XMMatrixLookAtLH(pCamera->GetPositionVector(), pCamera->GetCameraLook(), pCamera->GetCameraUp());
	projection = XMMatrixOrthographicLH(static_cast<float>(width), static_cast<float>(height), 1.0f, 10000.0f);

	return true;

}

void RenderToTexture::SetRenderTarget(ID3D11DeviceContext * pd3dDeviceContext, ID3D11DepthStencilView * pDepthStencilView)
{
	//·»´õ Å¸°Ù ¼³Á¤
	pd3dDeviceContext->OMSetRenderTargets(1, &RenderTagetView, pDepthStencilView);


}

void RenderToTexture::ClearRenderTarget(ID3D11DeviceContext * pd3dDeviceContext, ID3D11DepthStencilView * pDepthStencilView, float color[])
{
	pd3dDeviceContext->ClearRenderTargetView(RenderTagetView, color);
	pd3dDeviceContext->ClearDepthStencilView(pDepthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0.0f);

}

void RenderToTexture::Release()
{
	Memory::SafeRelease(RenderTagetTexture2D);
	Memory::SafeRelease(RenderTagetView);
	Memory::SafeDelete(RenderTargetShaderResoureView);

}
