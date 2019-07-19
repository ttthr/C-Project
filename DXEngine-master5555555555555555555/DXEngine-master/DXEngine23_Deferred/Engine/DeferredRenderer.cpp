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
	//정점 만들기
	float right = static_cast<float>(screenWidth / 2);
	float left = right * -1.0f;
	float top = static_cast<float>(screenHeight / 2);
	float bottom = top * -1.0f;

	//정점 배열 만들기
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

	//버텍스 버퍼 서술자
	D3D11_BUFFER_DESC vbDesc;
	ZeroMemory(&vbDesc, sizeof(D3D11_BUFFER_DESC));

	vbDesc.ByteWidth = sizeof(DeferredVertex) * vertexCount;
	vbDesc.CPUAccessFlags = 0;
	vbDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vbDesc.MiscFlags = 0;
	vbDesc.Usage = D3D11_USAGE_DEFAULT;


	// 정점 배열 정보 넣어줄 구조체.
	D3D11_SUBRESOURCE_DATA vbData;
	ZeroMemory(&vbData, sizeof(D3D11_SUBRESOURCE_DATA));
	vbData.pSysMem = &vertices;

	// 정점 버퍼 생성.
	HRESULT result = pd3dDevice->CreateBuffer(&vbDesc, &vbData, &vertexBuffer);

	//오류 확인
	if (IsError(result, TEXT("Deferred 정점 버퍼 생성 실패")))
	{
		return false;
	}

	DWORD indices[]
	{
		0,1,2,
		0,2,3
	};

	indexCount = ARRAYSIZE(indices);

	// 버퍼 서술자.
	D3D11_BUFFER_DESC ibDesc;
	ZeroMemory(&ibDesc, sizeof(D3D11_BUFFER_DESC));

	ibDesc.ByteWidth = sizeof(DWORD) * indexCount;
	ibDesc.CPUAccessFlags = 0;
	ibDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	ibDesc.MiscFlags = 0;
	ibDesc.Usage = D3D11_USAGE_DEFAULT;

	// 인덱스 배열 정보 넣어줄 구조체.
	D3D11_SUBRESOURCE_DATA ibData;
	ZeroMemory(&ibData, sizeof(D3D11_SUBRESOURCE_DATA));
	ibData.pSysMem = &indices;

	// 인덱스 버퍼 생성.
	result = pd3dDevice->CreateBuffer(&ibDesc, &ibData, &indexBuffer);

	//오류 확인 
	if (IsError(result, TEXT("Deferred 인덱스 버퍼 생성 실패")))
	{
		return false;
	}

	
	//상수 버퍼 생성 ( 월드 행렬용 )

	//서술자
	D3D11_BUFFER_DESC cbDesc;
	ZeroMemory(&cbDesc, sizeof(D3D11_BUFFER_DESC));

	cbDesc.ByteWidth = sizeof(XMMATRIX);
	cbDesc.CPUAccessFlags = 0;
	cbDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cbDesc.MiscFlags = 0;
	cbDesc.Usage = D3D11_USAGE_DEFAULT;

	//월드 행렬 만들기 

	XMMATRIX world = XMMatrixTranspose(XMMatrixIdentity());

	//서브리소스 데이터
	D3D11_SUBRESOURCE_DATA cbData;
	ZeroMemory(&cbData, sizeof(D3D11_SUBRESOURCE_DATA));
	cbData.pSysMem = &world;

	//버퍼 생성
	result = pd3dDevice->CreateBuffer(&cbDesc, &cbData, &constantBuffer);

	//오류 확인
	if (IsError(result, TEXT("Deferred 상수버퍼 생성 실패")))
	{
		return false;
	}

	//인풋 레이아웃 생성
	result = pd3dDevice->CreateInputLayout(inputLayoutDesc,
		ARRAYSIZE(inputLayoutDesc),
		pVertexShaderBuffer->GetBufferPointer(),
		pVertexShaderBuffer->GetBufferSize(),
		&inputLayout);

	//오류 확인
	if (IsError(result, TEXT("Deferred 입력 레이아웃 생성 실패")))
	{
		return false;
	}

	// 뷰/투영 행렬
	view = XMMatrixLookAtLH(pCamera->GetPositionVector(), pCamera->GetCameraLook(), pCamera->GetCameraUp());
	proj = XMMatrixOrthographicLH(static_cast<float>(screenWidth), static_cast<float>(screenHeight), pCamera->GetNearZ(), pCamera->GetFarZ());

	return true;
}

void DeferredRenderer::DiferredRender(ID3D11DeviceContext * pd3dDeviceContext)
{
	//바인딩
	UINT stride = sizeof(DeferredVertex);
	UINT offset = 0;

	// 정점 버퍼 전달.
	pd3dDeviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);

	// 인덱스 버퍼 바인딩.
	pd3dDeviceContext->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0);

	// 입력 레이아웃 전달.
	pd3dDeviceContext->IASetInputLayout(inputLayout);

	// 위상 설정.
	pd3dDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	pd3dDeviceContext->DrawIndexed(indexCount, 0, 0);

}
void DeferredRenderer::DiferredUpdate(ID3D11DeviceContext * pd3dDeviceContext)
{
	//상수 버퍼 바인딩
	pd3dDeviceContext->VSSetConstantBuffers(0, 1, &constantBuffer);


}
void DeferredRenderer::Release()
{
	Memory::SafeRelease(vertexBuffer);
	Memory::SafeRelease(indexBuffer);
	Memory::SafeRelease(constantBuffer);
	Memory::SafeRelease(inputLayout);

}
