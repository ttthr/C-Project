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
	//삼각형 정점 버퍼
	Vertex vertexArr[] = 
	{
		Vertex(0.0f, 0.5f, 0.5f),
		Vertex(0.5f, -0.5f, 0.5f),
		Vertex(-0.5f, -0.5f, 0.5f),

	};
	//배열 크기 저장하기
	nVertices = ARRAYSIZE(vertexArr);


	D3D11_BUFFER_DESC VerTexBufferDesc; //서술자
	ZeroMemory(&VerTexBufferDesc, sizeof(D3D11_BUFFER_DESC)); //초기화
	VerTexBufferDesc.ByteWidth = sizeof(Vertex) *  nVertices; //바이트 수 계산
	VerTexBufferDesc.CPUAccessFlags = 0; // CPU가 접근못하게 0으로 설정해주면됨
	VerTexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER; // 버텍스 버퍼 사용
	VerTexBufferDesc.MiscFlags = 0; //버퍼를 다른용도로 만들때 넣는 곳
	VerTexBufferDesc.Usage = D3D11_USAGE_DEFAULT; //CPU가 접근못함 

	//정점 배열 정보를 넣어줄 구조체
	D3D11_SUBRESOURCE_DATA SubResouceVB;
	ZeroMemory(&SubResouceVB, sizeof(D3D11_SUBRESOURCE_DATA));
	SubResouceVB.pSysMem = vertexArr;

	//정점 버퍼 생성
	HRESULT hResult;
	hResult = pDevice->CreateBuffer(&VerTexBufferDesc, &SubResouceVB, &VertexBuffer);

	if (FAILED(hResult))
	{
		MessageBox(NULL, TEXT("정점버퍼 생성 실패"), TEXT("오류"), MB_OK);
		return false;
	}

	//입력 레이아웃 셋팅
	D3D11_INPUT_ELEMENT_DESC Layout[] =
	{
		{"POSITION", 0 ,DXGI_FORMAT_R32G32B32A32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0},

	};

	hResult = pDevice->CreateInputLayout(Layout, ARRAYSIZE(Layout), VertexShaderBuffer->GetBufferPointer(),VertexShaderBuffer->GetBufferSize(), &inputLayout);
	
	if (FAILED(hResult))
	{
		MessageBox(NULL, TEXT("입력 레이아웃 생성 실패"), TEXT("오류"), MB_OK);
		return false;
	}

	return true;
}

void Mesh::RenderBuffers(ID3D11DeviceContext * pDeviceContext)
{
	Stride = sizeof(Vertex);
	Offset = 0;
	//정점 버퍼 전달
	pDeviceContext->IASetVertexBuffers(0, 1, &VertexBuffer, &Stride, &Offset);
	//입력 레이아웃 전달
	pDeviceContext->IAGetInputLayout(&inputLayout);
	//위상 설정
	pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	//그리기
	pDeviceContext->Draw(nVertices, 0);
}
