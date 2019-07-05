//상수 버퍼 받아오기
cbuffer PerObjectBuffer : register(b0)
{
	matrix world;
};

cbuffer PerSceneBuffer : register(b1)
{
	matrix view;
	matrix projection;
	//float3 worldLightPosition;
};


struct VS_INPUT
{
	float4 position : POSITION;
	float2 texCoord : TEXCOORD0;
	float3 normal : NORMAL;
};
struct VS_OUTPUT
{
	float4 position : SV_POSITION;
	float2 texCoord : TEXCOORD0;
	float3 normal : NORMAL;
	float3 diffuse : TEXCOORD1;
};

VS_OUTPUT(VS_INPUT input)
{

	VS_OUTPUT output;
	output.position = mul(input.position, world);

	//임시 라이트 위치 설정
	float3 worldLightPosition
		= float3(-500.0f, 500.0f, -500.0f);

	//라이트 방향 구하기
	float3 LightDir = normalize(output.position.xyz - worldLightPosition);
	//월드 좌표계기준 노멀값
	float worldNormal = normalize(mul(input.normal, (float3x3)world)));
	//내적 ( 사이각 구하기 )
	//내적 연산을 위해 - 붙인 것임
	output.diffuse = dot(-LightDir, worldNormal);
	output.position = mul(output.position, view);
	output.position = mul(output.position, projection);

	output.uv = input.uv;


	return output;
}