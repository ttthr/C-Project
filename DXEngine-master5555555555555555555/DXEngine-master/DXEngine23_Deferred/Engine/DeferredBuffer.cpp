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

	//������
	D3D11_TEXTURE2D_DESC desc;
	ZeroMemory(&desc, sizeof(D3D11_TEXTURE2D_DESC));
	desc.Width = width;
	desc.Height = height;
	desc.MipLevels = 1;
	desc.ArraySize = 1; //���� ���� ��
	desc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	desc.SampleDesc.Count = 1; //��Ƽ�˸��ƽ� 1�̸� ���ϴ� ��
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE; // Draw�� �ɸ��� ����Ÿ���� �׸��� / �׸��� �� ���� �ϰڴٴ��ǹ�
	desc.CPUAccessFlags = 0;
	desc.MiscFlags = 0;

	// Deferred �ؽ��� ����
	HRESULT h;
	for (int i = 0; i < BUFFERCOUNT; ++i)
	{
		h = pd3dDevice->CreateTexture2D(&desc, NULL, &renderTargetTExtureArray[i]);

		if (IsError(h, TEXT("Deferred ���� Ÿ�� �ؽ��� ���� ����")))
		{
			return false;
		}
	}

	//������
	D3D11_RENDER_TARGET_VIEW_DESC Rtvdesc;
	ZeroMemory(&Rtvdesc, sizeof(D3D11_RENDER_TARGET_VIEW_DESC));
	Rtvdesc.Format = desc.Format;
	Rtvdesc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
	Rtvdesc.Texture2D.MipSlice = 0;

	//Deferred ���� Ÿ�� �� ����
	for (int i = 0; i < BUFFERCOUNT; ++i)
	{
		h = pd3dDevice->CreateRenderTargetView(renderTargetTExtureArray[i], &Rtvdesc, &renderTargetViewArray[i]);

		if (IsError(h, TEXT("Deferred ���� Ÿ�� ���� ����")))
		{
			return false;
		}
	}
	// ���̴� ���ҽ� �� ����
	D3D11_SHADER_RESOURCE_VIEW_DESC shaderDesc;
	ZeroMemory(&shaderDesc, sizeof(D3D11_SHADER_RESOURCE_VIEW_DESC));
	shaderDesc.Format = desc.Format;
	shaderDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	shaderDesc.Texture2D.MostDetailedMip = 0;
	shaderDesc.Texture2D.MipLevels = 1;

	//Deferred ���̴� ���ҽ� �� ����
	for (int i = 0; i < BUFFERCOUNT; ++i)
	{
		h = pd3dDevice->CreateShaderResourceView(renderTargetTExtureArray[i], &shaderDesc, &renderTargetSRVArray[i]);

		if (IsError(h, TEXT("Deferred ���̴� ���ҽ� �� ���� ����")))
		{
			return false;
		}
	}


	return true;
}

void DeferredBuffer::SetRenderTargets(ID3D11DeviceContext * pd3dDeviceContext, ID3D11DepthStencilView * pd3dDepthStencilView)
{
	//���� Ÿ�� �ΰ� �ѱ�
	pd3dDeviceContext->OMSetRenderTargets(BUFFERCOUNT, renderTargetViewArray, pd3dDepthStencilView);
	
}

void DeferredBuffer::ClearRenderTargets(ID3D11DeviceContext * pd3dDeviceContext, ID3D11DepthStencilView * pd3dDepthStencilView, float color[])
{
	//���� Ÿ�� Ŭ����
	for (int i = 0; i < BUFFERCOUNT; ++i)
	{
		pd3dDeviceContext->ClearRenderTargetView(renderTargetViewArray[i], color);
	}
	//����/���ٽ� Ŭ����
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
