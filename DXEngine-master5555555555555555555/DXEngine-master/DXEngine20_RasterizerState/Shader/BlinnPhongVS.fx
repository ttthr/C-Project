// ��� ����.
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
};
struct vs_output
{
	float4 position   : SV_POSITION;
	float2 texCoord   : TEXCOORD0;
	float3 diffuse    : TEXCOORD1;
	float3 halfVector : TEXCOORD2;
	float3 normal     : NORMAL;
};

vs_output main(vs_input input)
{
	vs_output output;
	//���庯ȯ
	output.position = mul(input.position, world);
	//����Ʈ ����
	//���� ���ͷ� ����� �����
	float3 lightDir = normalize(output.position.xyz - worldLightPosition);
	//���� ���
	output.normal = normalize(mul(input.normal, (float3x3)world));
	//�� ����
	float3 viewDir = normalize(output.position.xyz - worldCameraPosition);
	//���� ����
	output.halfVector = normalize((-lightDir) + (-viewDir));
	//��/������ȯ
	output.position = mul(output.position, viewProjection);
	//�ؽ��� ��ǥ
	output.texCoord = input.texCoord;
	//���ݻ籤(��ǻ��)
	// -1 ~ 1 ���� ���� ���´�.
	output.diffuse = dot(-lightDir, output.normal);

	return output;
}