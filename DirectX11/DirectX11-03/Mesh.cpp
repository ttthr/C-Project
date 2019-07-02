#include "Mesh.h"

Mesh::Mesh()
{
	VertexBuffer = NULL;
	inputLayout = NULL;
	nVertices = 0;
	Stride = 0;
	Offset = 0;

}

Mesh::~Mesh()
{
	VertexBuffer->Release();
	inputLayout->Release();
}

bool Mesh::InitailizeBuffers(ID3D11Device * pDevice, ID3DBlob * VertexShaderBuffer)
{
	//�ﰢ�� ���� ����
	Vertex vertexArr[] = 
	{
		Vertex(0.0f, 0.5f, 0.5f),
		Vertex(0.5f, -0.5f, 0.5f),
		Vertex(-0.5f, -0.5f, 0.5f),

	};
	//�迭 ũ�� �����ϱ�
	nVertices = ARRAYSIZE(vertexArr);


	D3D11_BUFFER_DESC VerTexBufferDesc; //������
	ZeroMemory(&VerTexBufferDesc, sizeof(D3D11_BUFFER_DESC)); //�ʱ�ȭ
	VerTexBufferDesc.ByteWidth = sizeof(Vertex) *  nVertices; //����Ʈ �� ���
	VerTexBufferDesc.CPUAccessFlags = 0; // CPU�� ���ٸ��ϰ� 0���� �������ָ��
	VerTexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER; // ���ؽ� ���� ���
	VerTexBufferDesc.MiscFlags = 0; //���۸� �ٸ��뵵�� ���鶧 �ִ� ��
	VerTexBufferDesc.Usage = D3D11_USAGE_DEFAULT; //CPU�� ���ٸ��� 

	//���� �迭 ������ �־��� ����ü
	D3D11_SUBRESOURCE_DATA SubResouceVB;
	ZeroMemory(&SubResouceVB, sizeof(D3D11_SUBRESOURCE_DATA));
	SubResouceVB.pSysMem = vertexArr;

	//���� ���� ����
	HRESULT hResult;
	hResult = pDevice->CreateBuffer(&VerTexBufferDesc, &SubResouceVB, &VertexBuffer);

	if (FAILED(hResult))
	{
		MessageBox(NULL, TEXT("�������� ���� ����"), TEXT("����"), MB_OK);
		return false;
	}

	//�Է� ���̾ƿ� ����
	D3D11_INPUT_ELEMENT_DESC Layout[] =
	{
		{"POSITION", 0 ,DXGI_FORMAT_R32G32B32A32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0},

	};

	hResult = pDevice->CreateInputLayout(Layout, ARRAYSIZE(Layout), VertexShaderBuffer->GetBufferPointer(),VertexShaderBuffer->GetBufferSize(), &inputLayout);
	
	if (FAILED(hResult))
	{
		MessageBox(NULL, TEXT("�Է� ���̾ƿ� ���� ����"), TEXT("����"), MB_OK);
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
	//�Է� ���̾ƿ� ����
	pDeviceContext->IAGetInputLayout(&inputLayout);
	//���� ����
	pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	//�׸���
	pDeviceContext->Draw(nVertices, 0);
}
