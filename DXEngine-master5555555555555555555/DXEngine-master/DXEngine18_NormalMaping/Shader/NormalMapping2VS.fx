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

struct vs_input
{
	float4 position : POSITION;
	float2 texCoord : TEXCOORD0;
	float3 normal   : NORMAL;
	float3 tangent  : TANGENT;
	float3 binormal : BINORMAL;
};
struct vs_output
{
	float4 position   : SV_POSITION;
	float2 texCoord   : TEXCOORD0;
	float3 lightDir   : TEXCOORD1;
	float3 viewDir    : TEXCOORD2;
	float3 normal     : TEXCOORD3;
	float3 tangent    : TEXCOORD4;
	float3 binormal   : TEXCOORD5;

};
//탄젠트 좌표축은 z좌표가 y축임
//표면공간으로 주어진 노멀값을 월드 노멀 값으로 만들어 줘야 한다.
//노멀, 탄젠트, 바이노멀값을 월드로 옴겨준다

vs_output main(vs_input input)
{
	vs_output output;
	//월드변환
	output.position = mul(input.position, world);
	//라이트 벡터
	//단위 벡터로 만들어 줘야함
	output.lightDir = normalize(output.position.xyz - worldLightPosition);
	//월드 노멀
	output.normal = normalize(mul(input.normal, (float3x3)world));
	//월드 탄젠트
	output.tangent = normalize(mul(input.tangent, (float3x3)world));
	//월드 바이노멀
	output.binormal = normalize(mul(input.binormal, (float3x3)world));
	//뷰 벡터
	output.viewDir = normalize(output.position.xyz - worldCameraPosition);
	//뷰/투영변환
	output.position = mul(output.position, viewProjection);
	//텍스쳐 좌표
	output.texCoord = input.texCoord;

	return output;
}