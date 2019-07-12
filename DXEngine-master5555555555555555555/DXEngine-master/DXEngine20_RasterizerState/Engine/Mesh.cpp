#include "Mesh.h"
#include "../Library/FBXLoader.h"

Mesh::Mesh()
{
}

Mesh::Mesh(float x, float y, float z)
{
	SetPosition(x, y, z);
}

Mesh::Mesh(LPCSTR fbxName , LPCTSTR shaderName, D3D11_FILL_MODE fillMode, D3D11_CULL_MODE cullMode)
{
	fileName = fbxName;
	material = new Material(shaderName);
	this->fillMode = fillMode;
	this->cullMode = cullMode;
}

Mesh::~Mesh()
{
	Memory::SafeRelease(vertexBuffer);
	Memory::SafeRelease(indexBuffer);
	Memory::SafeRelease(constantBuffer);
	Memory::SafeRelease(inputLayout);
	Memory::SafeRelease(RasterizerState);
	material->Release();
	Memory::SafeDelete(material);

}

bool Mesh::InitializeBuffers(ID3D11Device * device, ID3DBlob * vertexShaderBuffer)
{
	// FBX �ε�.
	HRESULT result = FBXLoader::LoadFBX(fileName, &vertices, &indices);
	if (IsError(result, TEXT("FBX �ε� ����")))
		return false;

	// �迭 ũ�� ����.
	nVertices = GetVertexCount();

	D3D11_BUFFER_DESC vbDesc;
	ZeroMemory(&vbDesc, sizeof(D3D11_BUFFER_DESC));

	vbDesc.ByteWidth = sizeof(Vertex) * nVertices;
	vbDesc.CPUAccessFlags = 0;
	vbDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vbDesc.MiscFlags = 0;
	vbDesc.Usage = D3D11_USAGE_DEFAULT;

	// ���� �迭 ���� �־��� ����ü.
	D3D11_SUBRESOURCE_DATA vbData;
	ZeroMemory(&vbData, sizeof(D3D11_SUBRESOURCE_DATA));
	vbData.pSysMem = &vertices[0];

	// ���� ���� ����.
	result = device->CreateBuffer(&vbDesc, &vbData, &vertexBuffer);
	if (IsError(result, TEXT("���� ���� ���� ����")))
	{
		return false;
	}

	//nIndices = ARRAYSIZE(indices);
	nIndices = GetIndexCount();

	// ���� ������.
	D3D11_BUFFER_DESC ibDesc;
	ZeroMemory(&ibDesc, sizeof(D3D11_BUFFER_DESC));

	ibDesc.ByteWidth = sizeof(DWORD) * nIndices;
	ibDesc.CPUAccessFlags = 0;
	ibDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	ibDesc.MiscFlags = 0;
	ibDesc.Usage = D3D11_USAGE_DEFAULT;

	// �ε��� �迭 ���� �־��� ����ü.
	D3D11_SUBRESOURCE_DATA ibData;
	ZeroMemory(&ibData, sizeof(D3D11_SUBRESOURCE_DATA));
	ibData.pSysMem = &indices[0];

	// �ε��� ���� ����.
	result = device->CreateBuffer(&ibDesc, &ibData, &indexBuffer);
	if (IsError(result, TEXT("�ε��� ���� ���� ����")))
	{
		return false;
	}

	// �Է� ���̾ƿ� ����.
	result = device->CreateInputLayout(
		inputLayoutDesc, 
		ARRAYSIZE(inputLayoutDesc),
		vertexShaderBuffer->GetBufferPointer(),
		vertexShaderBuffer->GetBufferSize(),
		&inputLayout
	);

	if (IsError(result, TEXT("�Է� ���̾ƿ� ���� ����")))
	{
		return false;
	}

	// ��� ���� ����.
	// DX ��켱 / HLSL ���켱.
	//PerObjectBuffer matrixData;
	matrixData.world = XMMatrixTranspose(GetWorldMatrix());		// ���� ��� ����.

	// ���� ������.
	D3D11_BUFFER_DESC cbDesc;
	ZeroMemory(&cbDesc, sizeof(D3D11_BUFFER_DESC));

	cbDesc.ByteWidth = sizeof(PerObjectBuffer);
	cbDesc.CPUAccessFlags = 0;
	cbDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cbDesc.MiscFlags = 0;
	cbDesc.Usage = D3D11_USAGE_DEFAULT;

	// �ε��� �迭 ���� �־��� ����ü.
	D3D11_SUBRESOURCE_DATA cbData;
	ZeroMemory(&cbData, sizeof(D3D11_SUBRESOURCE_DATA));
	cbData.pSysMem = &matrixData;

	// ���� ����.
	result = device->CreateBuffer(&cbDesc, &cbData, &constantBuffer);
	if (IsError(result, TEXT("������Ʈ ��� ���� ���� ����")))
	{
		return false;
	}
	
	CreateRasterizerState1(device);
	
	return true;
}



bool Mesh::InitializeBuffers(ID3D11Device * device)
{
	return InitializeBuffers(
		device, 
		material->GetVertexShader()->GetShaderBuffer()
	);
}

void Mesh::RenderBuffers(ID3D11DeviceContext * deviceContext)
{
	UINT stride = sizeof(Vertex);
	UINT offset = 0;

	// ���� ���� ����.
	deviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);

	// �ε��� ���� ���ε�.
	deviceContext->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0);

	// �Է� ���̾ƿ� ����.
	deviceContext->IASetInputLayout(inputLayout);

	// ���� ����.
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	//�����Ͷ�����
	//if (this->input->IsKeyDown(Keyboard::Keys::R))
	//{
	//	deviceContext->RSSetState(RasterizerState);
	//	IsOn = true;
	//}
	//else if (this->input->IsKeyDown(Keyboard::Keys::T) && IsOn == true)
	//{
	//	deviceContext->RSSetState(RasterizerState);
	//	IsOn = false;
	//}

	// �׸���.
	//deviceContext->Draw(nVertices, 0);
	deviceContext->DrawIndexed(nIndices, 0, 0);
}

void Mesh::Update(ID3D11DeviceContext * deviceContext)
{
	// ��ġ(ȸ��, ������) ���� ������Ʈ.
	// ���� ȸ�� �� ������ Y ȸ�� �� ���ϱ�.
	//XMFLOAT3 rot = GetRotation();
	//rot.y += 0.5f;

	//// ������ ȸ�� �� �����ϱ�.
	//SetRotation(rot.x, rot.y, rot.z);

	//// ���� ��� ������Ʈ�ϱ�.
	matrixData.world = XMMatrixTranspose(GetWorldMatrix());

	// ��� ���ۿ� ����� ������ ������Ʈ�ϱ�.
	deviceContext->UpdateSubresource(constantBuffer, 0, 0, &matrixData, 0, 0);

	// ���� ��� ���� ���ε�.
	deviceContext->VSSetConstantBuffers(0, 1, &constantBuffer);
}

bool Mesh::CompileShaders(ID3D11Device * device)
{
	if (material->CompileShaders(device) == false)
	{
		return false;
	}
	return true;
}

bool Mesh::CreateShaders(ID3D11Device * device)
{
	if (material->CreateShaders(device) == false)
	{
		return false;
	}
	return true;
}

void Mesh::AddTexture(LPCTSTR fileName)
{
	material->AddTexture(fileName);
}

void Mesh::BindTextures(ID3D11DeviceContext * deviceContext)
{
	material->BindTextures(deviceContext);
}

bool Mesh::CreateSamplerState(ID3D11Device * device)
{
	if (material->CreateSamplerState(device) == false)
	{
		return false;
	}
	return true;
}

void Mesh::BindSamplerState(ID3D11DeviceContext * deviceContext)
{
	material->BindSamplerState(deviceContext);
}

bool Mesh::LoadTextures(ID3D11Device * device)
{
	if (material->LoadTextures(device) == false)
	{
		return false;
	}
	return true;
}

void Mesh::BindShaders(ID3D11DeviceContext * deviceContext)
{
	material->BindShaders(deviceContext);
}

XMMATRIX Mesh::GetWorldMatrix()
{
	return GetScaleMatrix() * GetRotationMatrix() * GetTranslationMatrix();
}

XMMATRIX Mesh::GetTranslationMatrix()
{
	return XMMatrixTranslation(position.x, position.y, position.z);
}

XMMATRIX Mesh::GetRotationMatrix()
{
	XMMATRIX rotX = XMMatrixRotationX(XMConvertToRadians(rotation.x));
	XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(rotation.y));
	XMMATRIX rotZ = XMMatrixRotationZ(XMConvertToRadians(rotation.z));

	return rotZ * rotX * rotY;
}

XMMATRIX Mesh::GetScaleMatrix()
{
	return XMMatrixScaling(scale.x, scale.y, scale.z);
}

void Mesh::CreateRasterizerState1(ID3D11Device * pd3dDevice)
{
	// Default 
	D3D11_RASTERIZER_DESC d3dRasterizerDesc;
	ZeroMemory(&d3dRasterizerDesc, sizeof(D3D11_RASTERIZER_DESC));
	d3dRasterizerDesc.CullMode = D3D11_CULL_NONE;
	d3dRasterizerDesc.FillMode = D3D11_FILL_WIREFRAME;
	pd3dDevice->CreateRasterizerState(&d3dRasterizerDesc, &RasterizerState);

}

 bool Mesh::CreateRasterizerState(ID3D11Device *pd3dDevice)
 {
	 // Default 
	 D3D11_RASTERIZER_DESC d3dRasterizerDesc;
	 ZeroMemory(&d3dRasterizerDesc, sizeof(D3D11_RASTERIZER_DESC));
	 d3dRasterizerDesc.CullMode = D3D11_CULL_NONE;
	 d3dRasterizerDesc.FillMode = D3D11_FILL_WIREFRAME;
	 HRESULT h = pd3dDevice->CreateRasterizerState(&d3dRasterizerDesc, &RasterizerState);
	 if (IsError(h, TEXT("�����Ͷ����� ���� ����")))
	 {
		 return false;
	 }
	 return true;
}

 void Mesh::BindRasterizerState(ID3D11DeviceContext * pd3dDeviceContext)
 {
	 pd3dDeviceContext->RSSetState(RasterizerState);
 }

