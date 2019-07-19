// 상수 버퍼.
cbuffer perObjectBuffer : register(b0)
{
	matrix world;
};

cbuffer perSceneBuffer : register(b1)
{
	matrix viewProjection;
};

struct vs_input
{
	float4 position : POSITION;
	float3 texCoord : TEXCOORD0;
	float3 normal   : NORMAL;
	float3 tangent  : TANGENT;
	float3 binormal : BINORMAL;
};
struct vs_output
{
	float4 position  : SV_POSITION;
	float3 texCoord  : TEXCOORD0;

};

vs_output main(vs_input input)
{
	vs_output output;
	//월드변환
	output.position = mul(input.position, world);
	output.position = mul(output.position, viewProjection);

	//큐브맵 UV 설정
	output.texCoord = input.position.xyz;


	return output;
}