// 상수 버퍼.
cbuffer perObjectBuffer : register(b0)
{
	matrix world;
};

cbuffer perSceneBuffer : register(b1)
{
	matrix viewProjection; //두개합쳐서넘길것
	float3 worldLightPosition;
	float3 worldCameraPosition;

};

// 정점 셰이더 입력.
struct vs_input
{
	float4 position : POSITION;
	float2 texCoord : TEXCOORD0;
	float3 normal   : NORMAL;
};

// 정점 셰이더 출력.
struct vs_output
{
	float4 position   : SV_POSITION;
	float2 texCoord   : TEXCOORD0;
	float3 diffuse    : TEXCOORD1;
	float3 viewDir    : TEXCOORD2;
	float3 reflection : TEXCOORD3;
};

// Entry Point(메인 함수).
vs_output main(vs_input input)
{
	vs_output output;

	// 공간 변환.
	// 월드-뷰-투영 변환.
	output.position = mul(input.position, world);


	// 라이트 방향 구하기.
	float3 lightDir 
		= normalize(output.position.xyz - worldLightPosition);

	// 월드 좌표계기준 노멀.
	float3 worldNormal 
		= normalize(mul(input.normal, (float3x3)world));

	// 뷰 벡터 만들기
	// 정점에서 카메라 위치 빼기 ( 바라보는 방향 구하기 )
	float3 viewDir = normalize(output.position.xyz - worldCameraPosition);
	output.viewDir = viewDir;

	//반사벡터 구하기
	//포지션 + 2n ( -P x n )
	output.reflection = reflect(lightDir, worldNormal);

	// 내적 연산(코사인 구하기).
	output.diffuse = dot(-lightDir, worldNormal);

	// 뷰,프로젝션 행렬 곱 넘긴 것
	output.position = mul(output.position, viewProjection);
	

	output.texCoord = input.texCoord;

	return output;
}