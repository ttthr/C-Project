#include "DeferredBuffer.h"



DeferredBuffer::DeferredBuffer()
	:textureWidth(0), textureHeight(0)
{
	for (int i = 0; i < BUFFERCOUNT; ++i)
	{
		renderTargetTExtureArray[i] = NULL;
		renderTargetViewArray[i] = NULL;
		renderTargetSRVArray[i] = NULL;
	}

}


DeferredBuffer::~DeferredBuffer()
{


}

bool DeferredBuffer::Initailize(ID3D11Device * pd3dDevice, int width, int height)
{
	textureWidth = width;
	textureHeight = height;

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

	// Deferred ÅØ½ºÃÄ »ý¼º
	HRESULT h;
	for (int i = 0; i < BUFFERCOUNT; ++i)
	{
		h = pd3dDevice->CreateTexture2D(&desc, NULL, &renderTargetTExtureArray[i]);

		if (IsError(h, TEXT("Deferred ·»´õ Å¸°Ù ÅØ½ºÃÄ »ý¼º ½ÇÆÐ")))
		{
			return false;
		}
	}

	//¼­¼úÀÚ
	D3D11_RENDER_TARGET_VIEW_DESC Rtvdesc;
	ZeroMemory(&Rtvdesc, sizeof(D3D11_RENDER_TARGET_VIEW_DESC));
	Rtvdesc.Format = desc.Format;
	Rtvdesc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
	Rtvdesc.Texture2D.MipSlice = 0;

	//Deferred ·»´õ Å¸°Ù ºä »ý¼º
	for (int i = 0; i < BUFFERCOUNT; ++i)
	{
		h = pd3dDevice->CreateRenderTargetView(renderTargetTExtureArray[i], &Rtvdesc, &renderTargetViewArray[i]);

		if (IsError(h, TEXT("Deferred ·»´õ Å¸°Ù »ý¼º ½ÇÆÐ")))
		{
			return false;
		}
	}
	// ¼ÎÀÌ´õ ¸®¼Ò½º ºä »ý¼º
	D3D11_SHADER_RESOURCE_VIEW_DESC shaderDesc;
	ZeroMemory(&shaderDesc, sizeof(D3D11_SHADER_RESOURCE_VIEW_DESC));
	shaderDesc.Format = desc.Format;
	shaderDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	shaderDesc.Texture2D.MostDetailedMip = 0;
	shaderDesc.Texture2D.MipLevels = 1;

	//Deferred ¼ÎÀÌ´õ ¸®¼Ò½º ºä »ý¼º
	for (int i = 0; i < BUFFERCOUNT; ++i)
	{
		h = pd3dDevice->CreateShaderResourceView(renderTargetTExtureArray[i], &shaderDesc, &renderTargetSRVArray[i]);

		if (IsError(h, TEXT("Deferred ¼ÎÀÌ´õ ¸®¼Ò½º ºä »ý¼º ½ÇÆÐ")))
		{
			return false;
		}
	}


	return true;
}

void DeferredBuffer::SetRenderTargets(ID3D11DeviceContext * pd3dDeviceContext, ID3D11DepthStencilView * pd3dDepthStencilView)
{
	//·»´õ Å¸°Ù µÎ°³ ³Ñ±è
	pd3dDeviceContext->OMSetRenderTargets(BUFFERCOUNT, renderTargetViewArray, pd3dDepthStencilView);
	
}

void DeferredBuffer::ClearRenderTargets(ID3D11DeviceContext * pd3dDeviceContext, ID3D11DepthStencilView * pd3dDepthStencilView, float color[])
{
	//·»´õ Å¸°Ù Å¬¸®¾î
	for (int i = 0; i < BUFFERCOUNT; ++i)
	{
		pd3dDeviceContext->ClearRenderTargetView(renderTargetViewArray[i], color);
	}
	//µª½º/½ºÅÙ½Ç Å¬¸®¾î
	pd3dDeviceContext->ClearDepthStencilView(pd3dDepthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
}

void DeferredBuffer::Release()
{
	for (int i = 0; i < BUFFERCOUNT; ++i)
	{
		Memory::SafeRelease(renderTargetTExtureArray[i]);
		Memory::SafeRelease(renderTargetViewArray[i]);
		Memory::SafeRelease(renderTargetSRVArray[i]);
	}
}
