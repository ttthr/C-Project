// ��� ����.
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
	//���庯ȯ
	output.position = mul(input.position, world);
	output.position = mul(output.position, viewProjection);

	//ť��� UV ����
	output.texCoord = input.position.xyz;


	return output;
}