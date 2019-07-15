// 상수 버퍼.
cbuffer perObjectBuffer : register(b0)
{
	matrix world;
};

cbuffer perSceneBuffer : register(b1)
{
	matrix viewProjection;
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
	float4 position      : SV_POSITION;
	float2 texCoord      : TEXCOORD0;
	float3 normal        : TEXCOORD1;
    float3 lightPosition : TEXCOORD2;
    float3 viewPosition  : TEXCOORD3;

};

// Entry Point(메인 함수).
// 정점위치를 건들여서 위치 변환 시킬 수 있다.(왜곡같은거)
// 멜팅셰이더
// ShaderX 책
// Gpu Gem 책
// 극좌표계, 구면좌표계 공부 할 것

vs_output main(vs_input input)
{
	vs_output output;

	// 공간 변환.
	output.position = mul(input.position, world);

	// 라이트 방향 구하기. ( 바라보는 방향 )
	output.lightPosition = normalize(output.position.xyz - worldLightPosition);

	// 월드 좌표계기준 노멀.
	output.normal = normalize(mul(input.normal, (float3x3)world));

	//카메라 위치
    output.viewPosition = worldCameraPosition;

	//공간 변환 마무리이
	output.position = mul(output.position, viewProjection);

	
	//텍스쳐 좌표 전달
	output.texCoord = input.texCoord;

	return output;

}