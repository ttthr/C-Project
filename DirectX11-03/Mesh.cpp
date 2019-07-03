#include "Mesh.h"

Mesh::Mesh()
{

}

Mesh::Mesh(float x, float y, float z)
{
	//메쉬 위치
	//SetPosition에서 Position에 넣어주고 있음
	SetPosition(x, y, z);

}
Mesh::~Mesh()
{
	if (VertexBuffer) { VertexBuffer->Release(); }
	if (inputLayout) { inputLayout->Release(); }
}

bool Mesh::InitailizeBuffers(ID3D11Device * pDevice, ID3DBlob * VertexShaderBuffer)
{
	//삼각형 정점 버퍼
	Vertex vertexArr[] =
	{
		//정점 배열에 색상 넣는거로 바꾸기
		/*Vertex(XMFLOAT3(0.0f, 0.5f, 0.5f), XMFLOAT4(1.0f,0.0f,0.0f,1.0f)),
		Vertex(XMFLOAT3(0.5f, -0.5f, 0.5f),XMFLOAT4(0.0f,1.0f,0.0f,1.0f)),
		Vertex(XMFLOAT3(-0.5f, -0.5f, 0.5f),XMFLOAT4(0.0f,0.0f,1.0f,1.0f)),*/
		//투영 좌표( 가운데가 0,0 )
		Vertex(XMFLOAT3( -0.5f, 0.5f, 0.5f),XMFLOAT4(1.0f,0.0f,0.0f,1.0f)),
		Vertex(XMFLOAT3( 0.5f,  0.5f, 0.5f),XMFLOAT4(0.0f,1.0f,0.0f,1.0f)),
		Vertex(XMFLOAT3( 0.5f, -0.5f, 0.5f),XMFLOAT4(0.0f,0.0f,1.0f,1.0f)),
		Vertex(XMFLOAT3(-0.5f, -0.5f, 0.5f),XMFLOAT4(0.0f,0.0f,1.0f,1.0f))

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
	//인덱스 배열 만들기
	//DWORD( unsingend long)
	DWORD indicesArr[] = 
	{
		0,1,2,
		0,2,3
	};

	nIndeices = ARRAYSIZE(indicesArr);

	//인덱스 버퍼 서술자 
	D3D11_BUFFER_DESC IndexBufferDesc; //서술자
	ZeroMemory(&IndexBufferDesc, sizeof(D3D11_BUFFER_DESC)); //초기화
	IndexBufferDesc.ByteWidth = sizeof(DWORD) *  nIndeices; //바이트 수 계산
	IndexBufferDesc.CPUAccessFlags = 0; // CPU가 접근못하게 0으로 설정해주면됨
	IndexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER; // 버텍스 버퍼 사용
	IndexBufferDesc.MiscFlags = 0; //버퍼를 다른용도로 만들때 넣는 곳
	IndexBufferDesc.Usage = D3D11_USAGE_DEFAULT; //CPU가 접근못함 

	//인덱스 정점 배열 정보를 넣어줄 구조체
	D3D11_SUBRESOURCE_DATA IndexSubResouceVB;
	ZeroMemory(&IndexSubResouceVB, sizeof(D3D11_SUBRESOURCE_DATA));
	IndexSubResouceVB.pSysMem = indicesArr;


	//인덱스 정점 버퍼 생성

	hResult = pDevice->CreateBuffer(&IndexBufferDesc, &IndexSubResouceVB, &IndexBuffer);

	if (FAILED(hResult))
	{
		MessageBox(NULL, TEXT("인덱스 버퍼 생성 실패"), TEXT("오류"), MB_OK);
		return false;
	}

	//입력 레이아웃 셋팅
	D3D11_INPUT_ELEMENT_DESC Layout[] =
	{
		{"POSITION", 0 ,DXGI_FORMAT_R32G32B32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0},
		{"COLOR", 0 ,DXGI_FORMAT_R32G32B32A32_FLOAT,0,12,D3D11_INPUT_PER_VERTEX_DATA,0},

	};

	hResult = pDevice->CreateInputLayout(Layout, ARRAYSIZE(Layout), VertexShaderBuffer->GetBufferPointer(),VertexShaderBuffer->GetBufferSize(), &inputLayout);
	
	if (FAILED(hResult))
	{
		MessageBox(NULL, TEXT("입력 레이아웃 생성 실패"), TEXT("오류"), MB_OK);
		return false;
	}

	//상수 버퍼 생성 ( 넘기기 )
	PerObjectBuffer MatrixConstantBuffer;
	MatrixConstantBuffer.World = XMMatrixTranspose(GetWorldMatrix()); //월드 행렬 셋팅
	
	// 상수 버퍼
	D3D11_BUFFER_DESC MatrixConstantBufferDesc; //서술자
	ZeroMemory(&IndexBufferDesc, sizeof(D3D11_BUFFER_DESC)); //초기화
	MatrixConstantBufferDesc.ByteWidth = sizeof(PerObjectBuffer);; //바이트 수 계산
	MatrixConstantBufferDesc.CPUAccessFlags = 0; // CPU가 접근못하게 0으로 설정해주면됨
	MatrixConstantBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER; // 버텍스 버퍼 사용
	MatrixConstantBufferDesc.MiscFlags = 0; //버퍼를 다른용도로 만들때 넣는 곳
	MatrixConstantBufferDesc.Usage = D3D11_USAGE_DEFAULT; //CPU가 접근못함 

	// 상수 버퍼
	D3D11_SUBRESOURCE_DATA MatrixConstantBufferSubResouceVB;
	ZeroMemory(&MatrixConstantBufferSubResouceVB, sizeof(D3D11_SUBRESOURCE_DATA));
	MatrixConstantBufferSubResouceVB.pSysMem = &MatrixConstantBuffer;

	hResult = pDevice->CreateBuffer(&MatrixConstantBufferDesc, &MatrixConstantBufferSubResouceVB, &ConstantBuffer);


	if (FAILED(hResult))
	{
		MessageBox(NULL, TEXT("상수 버퍼 생성 실패"), TEXT("오류"), MB_OK);
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
	//인덱스 버퍼 전달
	pDeviceContext->IASetIndexBuffer(IndexBuffer, DXGI_FORMAT_R32_UINT, 0);
	//입력 레이아웃 전달
	pDeviceContext->IASetInputLayout(inputLayout);
	//위상 설정
	pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	//그리기 정점버퍼
	//pDeviceContext->Draw(nVertices, 0);
	//그리기 인덱스버퍼
	pDeviceContext->DrawIndexed(nIndeices, 0, 0);
}

void Mesh::Update(ID3D11DeviceContext * pDeviceContext)
{
	//  스케일 , 회전 정보 업데이트 있어야함 나중엔
	//
	//
	//월드 행렬 바인딩
	pDeviceContext->VSSetConstantBuffers(0, 1, &ConstantBuffer);

}
XMMATRIX Mesh::GetWorldMatrix() const
{
	return XMMatrixTranslation(Position.x, Position.y, Position.z);
}

void Mesh::SetPosition(float x, float y, float z)
{
	Position = XMFLOAT3(x, y, z);
}
