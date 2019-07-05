#include "Mesh.h"
#include "FBXLoader.h"

Mesh::Mesh()
{

}

Mesh::Mesh(float x, float y, float z)
{
	//�޽� ��ġ
	//SetPosition���� Position�� �־��ְ� ����
	SetPosition(x, y, z);

}
Mesh::Mesh(LPCSTR FbxFileName)
{
	this->FbxFileName = FbxFileName;
}
Mesh::~Mesh()
{
	if (VertexBuffer) { VertexBuffer->Release(); }
	if (inputLayout) { inputLayout->Release(); }
}

bool Mesh::InitailizeBuffers(ID3D11Device * pDevice, ID3DBlob * VertexShaderBuffer)
{
	///*�ﰢ�� ���� ����
	//Vertex vertexArr[] =
	//{
	//	//���� �迭�� ���� �ִ°ŷ� �ٲٱ�
	//	/*Vertex(XMFLOAT3(0.0f, 0.5f, 0.5f), XMFLOAT4(1.0f,0.0f,0.0f,1.0f)),
	//	Vertex(XMFLOAT3(0.5f, -0.5f, 0.5f),XMFLOAT4(0.0f,1.0f,0.0f,1.0f)),
	//	Vertex(XMFLOAT3(-0.5f, -0.5f, 0.5f),XMFLOAT4(0.0f,0.0f,1.0f,1.0f)),*/
	//	//���� ��ǥ( ����� 0,0 )
	//	/*Vertex(XMFLOAT3( -0.5f, 0.5f, 0.5f),XMFLOAT4(1.0f,0.0f,0.0f,1.0f)),
	//	Vertex(XMFLOAT3( 0.5f,  0.5f, 0.5f),XMFLOAT4(0.0f,1.0f,0.0f,1.0f)),
	//	Vertex(XMFLOAT3( 0.5f, -0.5f, 0.5f),XMFLOAT4(0.0f,0.0f,1.0f,1.0f)),
	//	Vertex(XMFLOAT3(-0.5f, -0.5f, 0.5f),XMFLOAT4(0.0f,0.0f,0.0f,1.0f))*/
	//	Vertex(XMFLOAT3(-0.5f, 0.5f, 0.5f), XMFLOAT2(0.0f,0.0f)),
	//	Vertex(XMFLOAT3(0.5f,  0.5f, 0.5f), XMFLOAT2(1.0f,0.0f)),
	//	Vertex(XMFLOAT3(0.5f, -0.5f, 0.5f), XMFLOAT2(1.0f,1.0f)),
	//	Vertex(XMFLOAT3(-0.5f, -0.5f, 0.5f),XMFLOAT2(0.0f,1.0f))

	//};
	////�迭 ũ�� �����ϱ�
	//nVertices = ARRAYSIZE(vertexArr);

	//D3D11_BUFFER_DESC VerTexBufferDesc; //������
	//ZeroMemory(&VerTexBufferDesc, sizeof(D3D11_BUFFER_DESC)); //�ʱ�ȭ
	//VerTexBufferDesc.ByteWidth = sizeof(Vertex) *  nVertices; //����Ʈ �� ���
	//VerTexBufferDesc.CPUAccessFlags = 0; // CPU�� ���ٸ��ϰ� 0���� �������ָ��
	//VerTexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER; // ���ؽ� ���� ���
	//VerTexBufferDesc.MiscFlags = 0; //���۸� �ٸ��뵵�� ���鶧 �ִ� ��
	//VerTexBufferDesc.Usage = D3D11_USAGE_DEFAULT; //CPU�� ���ٸ��� 

	////���� �迭 ������ �־��� ����ü
	//D3D11_SUBRESOURCE_DATA SubResouceVB;
	//ZeroMemory(&SubResouceVB, sizeof(D3D11_SUBRESOURCE_DATA));
	//SubResouceVB.pSysMem = vertexArr;

	////���� ���� ����
	//HRESULT hResult;
	//hResult = pDevice->CreateBuffer(&VerTexBufferDesc, &SubResouceVB, &VertexBuffer);

	//if (FAILED(hResult))
	//{
	//	MessageBox(NULL, TEXT("�������� ���� ����"), TEXT("����"), MB_OK);
	//	return false;
	//}
	////�ε��� �迭 �����
	////DWORD( unsingend long)
	//DWORD indicesArr[] = 
	//{
	//	0,1,2,
	//	0,2,3
	//};

	//nIndeices = ARRAYSIZE(indicesArr);

	////�ε��� ���� ������ 
	//D3D11_BUFFER_DESC IndexBufferDesc; //������
	//ZeroMemory(&IndexBufferDesc, sizeof(D3D11_BUFFER_DESC)); //�ʱ�ȭ
	//IndexBufferDesc.ByteWidth = sizeof(DWORD) *  nIndeices; //����Ʈ �� ���
	//IndexBufferDesc.CPUAccessFlags = 0; // CPU�� ���ٸ��ϰ� 0���� �������ָ��
	//IndexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER; // ���ؽ� ���� ���
	//IndexBufferDesc.MiscFlags = 0; //���۸� �ٸ��뵵�� ���鶧 �ִ� ��
	//IndexBufferDesc.Usage = D3D11_USAGE_DEFAULT; //CPU�� ���ٸ��� 

	////�ε��� ���� �迭 ������ �־��� ����ü
	//D3D11_SUBRESOURCE_DATA IndexSubResouceVB;
	//ZeroMemory(&IndexSubResouceVB, sizeof(D3D11_SUBRESOURCE_DATA));
	//IndexSubResouceVB.pSysMem = indicesArr;


	////�ε��� ���� ���� ����

	//hResult = pDevice->CreateBuffer(&IndexBufferDesc, &IndexSubResouceVB, &IndexBuffer);

	//if (FAILED(hResult))
	//{
	//	MessageBox(NULL, TEXT("�ε��� ���� ���� ����"), TEXT("����"), MB_OK);
	//	return false;
	//}

	////�Է� ���̾ƿ� ����
	//D3D11_INPUT_ELEMENT_DESC Layout[] =
	//{
	//	{"POSITION", 0 ,DXGI_FORMAT_R32G32B32_FLOAT,0,D3D11_APPEND_ALIGNED_ELEMENT,D3D11_INPUT_PER_VERTEX_DATA,0},
	//	//{"COLOR", 0 ,DXGI_FORMAT_R32G32B32A32_FLOAT,0,D3D11_APPEND_ALIGNED_ELEMENT,D3D11_INPUT_PER_VERTEX_DATA,0},
	//    {"TEXCORD", 0 , DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA,0}

	//};

	//hResult = pDevice->CreateInputLayout(Layout, ARRAYSIZE(Layout), VertexShaderBuffer->GetBufferPointer(),VertexShaderBuffer->GetBufferSize(), &inputLayout);
	//
	//if (FAILED(hResult))
	//{
	//	MessageBox(NULL, TEXT("�Է� ���̾ƿ� ���� ����"), TEXT("����"), MB_OK);
	//	return false;
	//}

	////��� ���� ���� ( �ѱ�� )
	//PerObjectBuffer MatrixConstantBuffer;
	//MatrixConstantBuffer.World = XMMatrixTranspose(GetWorldMatrix()); //���� ��� ����
	//
	//// ��� ����
	//D3D11_BUFFER_DESC MatrixConstantBufferDesc; //������
	//ZeroMemory(&IndexBufferDesc, sizeof(D3D11_BUFFER_DESC)); //�ʱ�ȭ
	//MatrixConstantBufferDesc.ByteWidth = sizeof(PerObjectBuffer);; //����Ʈ �� ���
	//MatrixConstantBufferDesc.CPUAccessFlags = 0; // CPU�� ���ٸ��ϰ� 0���� �������ָ��
	//MatrixConstantBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER; // ���ؽ� ���� ���
	//MatrixConstantBufferDesc.MiscFlags = 0; //���۸� �ٸ��뵵�� ���鶧 �ִ� ��
	//MatrixConstantBufferDesc.Usage = D3D11_USAGE_DEFAULT; //CPU�� ���ٸ��� 

	//// ��� ����
	//D3D11_SUBRESOURCE_DATA MatrixConstantBufferSubResouceVB;
	//ZeroMemory(&MatrixConstantBufferSubResouceVB, sizeof(D3D11_SUBRESOURCE_DATA));
	//MatrixConstantBufferSubResouceVB.pSysMem = &MatrixConstantBuffer;

	//hResult = pDevice->CreateBuffer(&MatrixConstantBufferDesc, &MatrixConstantBufferSubResouceVB, &ConstantBuffer);

	//if (FAILED(hResult))
	//{
	//	MessageBox(NULL, TEXT("��� ���� ���� ����"), TEXT("����"), MB_OK);
	//	return false;
	//}
	//*/

	//FBX �ε�
	HRESULT hResult = FBXLoader::LoadFBX(this->FbxFileName, &vertices,&indices);

	if (IsError(hResult, TEXT("FBX�ε� ����")))
	{
		return false;
	}
	////�迭 ũ�� �����ϱ�
	nVertices = GetVerTexCount();

	D3D11_BUFFER_DESC VerTexBufferDesc; //������
	ZeroMemory(&VerTexBufferDesc, sizeof(D3D11_BUFFER_DESC)); //�ʱ�ȭ
	VerTexBufferDesc.ByteWidth = sizeof(Vertex) * nVertices; //����Ʈ �� ���
	VerTexBufferDesc.CPUAccessFlags = 0; // CPU�� ���ٸ��ϰ� 0���� �������ָ��
	VerTexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER; // ���ؽ� ���� ���
	VerTexBufferDesc.MiscFlags = 0; //���۸� �ٸ��뵵�� ���鶧 �ִ� ��
	VerTexBufferDesc.Usage = D3D11_USAGE_DEFAULT; //CPU�� ���ٸ��� 

	//���� �迭 ������ �־��� ����ü
	D3D11_SUBRESOURCE_DATA SubResouceVB;
	ZeroMemory(&SubResouceVB, sizeof(D3D11_SUBRESOURCE_DATA));
	SubResouceVB.pSysMem = &vertices[0];

	//���� ���� ����
	//HRESULT hResult;
	hResult = pDevice->CreateBuffer(&VerTexBufferDesc, &SubResouceVB, &VertexBuffer);

	if (FAILED(hResult))
	{
		MessageBox(NULL, TEXT("�������� ���� ����"), TEXT("����"), MB_OK);
		return false;
	}
	//�ε��� �迭 �����

	nIndeices = GetIndexCount();

	//�ε��� ���� ������ 
	D3D11_BUFFER_DESC IndexBufferDesc; //������
	ZeroMemory(&IndexBufferDesc, sizeof(D3D11_BUFFER_DESC)); //�ʱ�ȭ
	IndexBufferDesc.ByteWidth = sizeof(DWORD) * nIndeices; //����Ʈ �� ���
	IndexBufferDesc.CPUAccessFlags = 0; // CPU�� ���ٸ��ϰ� 0���� �������ָ��
	IndexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER; // ���ؽ� ���� ���
	IndexBufferDesc.MiscFlags = 0; //���۸� �ٸ��뵵�� ���鶧 �ִ� ��
	IndexBufferDesc.Usage = D3D11_USAGE_DEFAULT; //CPU�� ���ٸ��� 

	//�ε��� ���� �迭 ������ �־��� ����ü
	D3D11_SUBRESOURCE_DATA IndexSubResouceVB;
	ZeroMemory(&IndexSubResouceVB, sizeof(D3D11_SUBRESOURCE_DATA));
	IndexSubResouceVB.pSysMem = &indices[0];


	//�ε��� ���� ���� ����

	hResult = pDevice->CreateBuffer(&IndexBufferDesc, &IndexSubResouceVB, &IndexBuffer);

	if (FAILED(hResult))
	{
		MessageBox(NULL, TEXT("�ε��� ���� ���� ����"), TEXT("����"), MB_OK);
		return false;
	}

	//�Է� ���̾ƿ� ����

	hResult = pDevice->CreateInputLayout(
		inputLayoutDesc, 
		ARRAYSIZE(inputLayoutDesc),
		VertexShaderBuffer->GetBufferPointer(),
		VertexShaderBuffer->GetBufferSize(), 
		&inputLayout);
	
	if (FAILED(hResult))
	{
		MessageBox(NULL, TEXT("�Է� ���̾ƿ� ���� ����"), TEXT("����"), MB_OK);
		return false;
	}

	//��� ���� ���� ( �ѱ�� )
	PerObjectBuffer MatrixConstantBuffer;
	MatrixConstantBuffer.World = XMMatrixTranspose(GetWorldMatrix()); //���� ��� ����
	
	// ��� ����
	D3D11_BUFFER_DESC MatrixConstantBufferDesc; //������
	ZeroMemory(&IndexBufferDesc, sizeof(D3D11_BUFFER_DESC)); //�ʱ�ȭ
	MatrixConstantBufferDesc.ByteWidth = sizeof(PerObjectBuffer);; //����Ʈ �� ���
	MatrixConstantBufferDesc.CPUAccessFlags = 0; // CPU�� ���ٸ��ϰ� 0���� �������ָ��
	MatrixConstantBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER; // ���ؽ� ���� ���
	MatrixConstantBufferDesc.MiscFlags = 0; //���۸� �ٸ��뵵�� ���鶧 �ִ� ��
	MatrixConstantBufferDesc.Usage = D3D11_USAGE_DEFAULT; //CPU�� ���ٸ��� 

	// ��� ����
	D3D11_SUBRESOURCE_DATA MatrixConstantBufferSubResouceVB;
	ZeroMemory(&MatrixConstantBufferSubResouceVB, sizeof(D3D11_SUBRESOURCE_DATA));
	MatrixConstantBufferSubResouceVB.pSysMem = &MatrixConstantBuffer;

	hResult = pDevice->CreateBuffer(&MatrixConstantBufferDesc, &MatrixConstantBufferSubResouceVB, &ConstantBuffer);


	if (FAILED(hResult))
	{
		MessageBox(NULL, TEXT("��� ���� ���� ����"), TEXT("����"), MB_OK);
		return false;
	}
	return true;
}

void Mesh::RenderBuffers(ID3D11DeviceContext * pDeviceContext)
{
	Stride = sizeof(Vertex);
	Offset = 0;
	//���� ���� ����
	pDeviceContext->IASetVertexBuffers(0, 1, &VertexBuffer, &Stride, &Offset);
	//�ε��� ���� ����
	pDeviceContext->IASetIndexBuffer(IndexBuffer, DXGI_FORMAT_R32_UINT, 0);
	//�Է� ���̾ƿ� ����
	pDeviceContext->IASetInputLayout(inputLayout);
	//���� ����
	pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	//�׸��� ��������
	//pDeviceContext->Draw(nVertices, 0);
	//�׸��� �ε�������
	pDeviceContext->DrawIndexed(nIndeices, 0, 0);
}

void Mesh::Update(ID3D11DeviceContext * pDeviceContext)
{
	//  ������ , ȸ�� ���� ������Ʈ �־���� ���߿�
	//
	//
	//���� ��� ���ε�
	pDeviceContext->VSSetConstantBuffers(0, 1, &ConstantBuffer);

}
XMMATRIX Mesh::GetWorldMatrix()
{
	//������ * ���� * �̵� 
	//return  GetScaleMatrix() * GetRotationMatrix() * GetTranslationMatrix();
	XMMATRIX s = GetScaleMatrix();
	XMMATRIX r = GetRotationMatrix();
	XMMATRIX t = GetTranslationMatrix();

	return s * r * t;
}

XMMATRIX Mesh::GetTranslationMatrix()
{
	return XMMatrixTranslation(Position.x, Position.y, Position.z);
}

XMMATRIX Mesh::GetRotationMatrix()
{
	XMMATRIX mtxRotateX;
	XMMATRIX mtxRotateY;
	XMMATRIX mtxRotateZ;
	mtxRotateX = XMMatrixRotationX((float)XMConvertToRadians(Rotation.x));
	mtxRotateY = XMMatrixRotationY((float)XMConvertToRadians(Rotation.y));
	mtxRotateZ = XMMatrixRotationZ((float)XMConvertToRadians(Rotation.z));
	
	//XMMATRIX mtxRotate;
	//mtxRotate = XMMatrixRotationRollPitchYaw((float)XMConvertToRadians(Rotation.x), (float)XMConvertToRadians(Rotation.y), (float)XMConvertToRadians(Rotation.z));	
	//return mtxRotate;
	
	return  mtxRotateZ * mtxRotateX * mtxRotateY;
	
}

XMMATRIX Mesh::GetScaleMatrix()
{
	return XMMatrixScaling(Scale.x, Scale.y, Scale.z);
}

void Mesh::SetPosition(float x, float y, float z)
{
	Position = XMFLOAT3(x, y, z);
}

void Mesh::SetRotation(float x, float y, float z)
{
	Rotation = XMFLOAT3(x, y, z);
}

void Mesh::SetScale(float x, float y, float z)
{
	Scale = XMFLOAT3(x, y, z);
}
