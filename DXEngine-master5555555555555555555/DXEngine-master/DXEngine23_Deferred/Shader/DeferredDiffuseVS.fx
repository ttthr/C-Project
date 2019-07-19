// ��� ����.
cbuffer perObjectBuffer : register(b0)
{
	matrix world;
};

cbuffer perSceneBuffer : register(b1)
{
	matrix viewprojection;
    float3 worldLightPosition;
    //float3 worldCameraPosition;
};

struct vs_input
{
	float4 position : POSITION;
    float2 texCoord : TEXCOORD; //����ŧ���Ϸ���
};


struct vs_output
{
	float4 position : SV_POSITION;
	float2 texCoord : TEXCOORD;
    float3 lightDir : TEXCOORD1;
    //float3 viewDir  : TEXCOORD2; //����ŧ���Ϸ���
};

// ���� ���̴�.
//float4 main(float4 pos : POSITION, float4 color : COLOR) : SV_POSITION
vs_output main(vs_input input)
{
	vs_output output;

	// ���� ��ȯ.
	// ����-��-���� ��ȯ.
	output.position = mul(input.position, world);
    output.lightDir = normalize(worldLightPosition - output.position.xyz);
    output.position = mul(output.position, viewprojection);
	output.texCoord = input.texCoord;

	return output;
}