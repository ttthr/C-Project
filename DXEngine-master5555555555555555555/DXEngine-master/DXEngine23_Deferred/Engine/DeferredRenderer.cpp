#include "DeferredRenderer.h"



DeferredRenderer::DeferredRenderer()
	:vertexCount(0), indexCount(0)/*, vertexBuffer(NULL),indexBuffer(NULL),constantBuffer(NULL)*/
{

}
DeferredRenderer::~DeferredRenderer()
{


}

bool DeferredRenderer::Initialize(ID3D11Device * pd3dDevice, ID3DBlob * pVertexShaderBuffer, Camera * pCamera, UINT screenWidth, UINT screenHeight)
{
	//���� �����
	float right = static_cast<float>(screenWidth / 2);
	float left = right * -1.0f;
	float top = static_cast<float>(screenHeight / 2);
	float bottom = top * -1.0f;

	//���� �迭 �����
	DeferredVertex vertices[4];

	vertices[0].position = XMFLOAT3(left , top , 0);
	vertices[0].textureCoord = XMFLOAT2(0.0f, 0.0f);
	vertices[1].position = XMFLOAT3(right, top, 0);
	vertices[1].textureCoord = XMFLOAT2(1.0f, 0.0f);
	vertices[2].position = XMFLOAT3(right, bottom, 0);
	vertices[2].textureCoord = XMFLOAT2(1.0f, 1.0f);
	vertices[3].position = XMFLOAT3(left, bottom, 0);
	vertices[3].textureCoord = XMFLOAT2(0.0f, 1.0f);

	vertexCount = ARRAYSIZE(vertices);

	//���ؽ� ���� ������
	D3D11_BUFFER_DESC vbDesc;
	ZeroMemory(&vbDesc, sizeof(D3D11_BUFFER_DESC));

	vbDesc.ByteWidth = sizeof(DeferredVertex) * vertexCount;
	vbDesc.CPUAccessFlags = 0;
	vbDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vbDesc.MiscFlags = 0;
	vbDesc.Usage = D3D11_USAGE_DEFAULT;


	// ���� �迭 ���� �־��� ����ü.
	D3D11_SUBRESOURCE_DATA vbData;
	ZeroMemory(&vbData, sizeof(D3D11_SUBRESOURCE_DATA));
	vbData.pSysMem = &vertices;

	// ���� ���� ����.
	HRESULT result = pd3dDevice->CreateBuffer(&vbDesc, &vbData, &vertexBuffer);

	//���� Ȯ��
	if (IsError(result, TEXT("Deferred ���� ���� ���� ����")))
	{
		return false;
	}

	DWORD indices[]
	{
		0,1,2,
		0,2,3
	};

	indexCount = ARRAYSIZE(indices);

	// ���� ������.
	D3D11_BUFFER_DESC ibDesc;
	ZeroMemory(&ibDesc, sizeof(D3D11_BUFFER_DESC));

	ibDesc.ByteWidth = sizeof(DWORD) * indexCount;
	ibDesc.CPUAccessFlags = 0;
	ibDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	ibDesc.MiscFlags = 0;
	ibDesc.Usage = D3D11_USAGE_DEFAULT;

	// �ε��� �迭 ���� �־��� ����ü.
	D3D11_SUBRESOURCE_DATA ibData;
	ZeroMemory(&ibData, sizeof(D3D11_SUBRESOURCE_DATA));
	ibData.pSysMem = &indices;

	// �ε��� ���� ����.
	result = pd3dDevice->CreateBuffer(&ibDesc, &ibData, &indexBuffer);

	//���� Ȯ�� 
	if (IsError(result, TEXT("Deferred �ε��� ���� ���� ����")))
	{
		return false;
	}

	
	//��� ���� ���� ( ���� ��Ŀ� )

	//������
	D3D11_BUFFER_DESC cbDesc;
	ZeroMemory(&cbDesc, sizeof(D3D11_BUFFER_DESC));

	cbDesc.ByteWidth = sizeof(XMMATRIX);
	cbDesc.CPUAccessFlags = 0;
	cbDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cbDesc.MiscFlags = 0;
	cbDesc.Usage = D3D11_USAGE_DEFAULT;

	//���� ��� ����� 

	XMMATRIX world = XMMatrixTranspose(XMMatrixIdentity());

	//���긮�ҽ� ������
	D3D11_SUBRESOURCE_DATA cbData;
	ZeroMemory(&cbData, sizeof(D3D11_SUBRESOURCE_DATA));
	cbData.pSysMem = &world;

	//���� ����
	result = pd3dDevice->CreateBuffer(&cbDesc, &cbData, &constantBuffer);

	//���� Ȯ��
	if (IsError(result, TEXT("Deferred ������� ���� ����")))
	{
		return false;
	}

	//��ǲ ���̾ƿ� ����
	result = pd3dDevice->CreateInputLayout(inputLayoutDesc,
		ARRAYSIZE(inputLayoutDesc),
		pVertexShaderBuffer->GetBufferPointer(),
		pVertexShaderBuffer->GetBufferSize(),
		&inputLayout);

	//���� Ȯ��
	if (IsError(result, TEXT("Deferred �Է� ���̾ƿ� ���� ����")))
	{
		return false;
	}

	// ��/���� ���
	view = XMMatrixLookAtLH(pCamera->GetPositionVector(), pCamera->GetCameraLook(), pCamera->GetCameraUp());
	proj = XMMatrixOrthographicLH(static_cast<float>(screenWidth), static_cast<float>(screenHeight), pCamera->GetNearZ(), pCamera->GetFarZ());

	return true;
}

void DeferredRenderer::DiferredRender(ID3D11DeviceContext * pd3dDeviceContext)
{
	//���ε�
	UINT stride = sizeof(DeferredVertex);
	UINT offset = 0;

	// ���� ���� ����.
	pd3dDeviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);

	// �ε��� ���� ���ε�.
	pd3dDeviceContext->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0);

	// �Է� ���̾ƿ� ����.
	pd3dDeviceContext->IASetInputLayout(inputLayout);

	// ���� ����.
	pd3dDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	pd3dDeviceContext->DrawIndexed(indexCount, 0, 0);

}
void DeferredRenderer::DiferredUpdate(ID3D11DeviceContext * pd3dDeviceContext)
{
	//��� ���� ���ε�
	pd3dDeviceContext->VSSetConstantBuffers(0, 1, &constantBuffer);


}
void DeferredRenderer::Release()
{
	Memory::SafeRelease(vertexBuffer);
	Memory::SafeRelease(indexBuffer);
	Memory::SafeRelease(constantBuffer);
	Memory::SafeRelease(inputLayout);

}
