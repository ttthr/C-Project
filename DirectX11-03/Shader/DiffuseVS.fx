//��� ���� �޾ƿ���
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

	//�ӽ� ����Ʈ ��ġ ����
	float3 worldLightPosition
		= float3(-500.0f, 500.0f, -500.0f);

	//����Ʈ ���� ���ϱ�
	float3 LightDir = normalize(output.position.xyz - worldLightPosition);
	//���� ��ǥ����� ��ְ�
	float worldNormal = normalize(mul(input.normal, (float3x3)world)));
	//���� ( ���̰� ���ϱ� )
	//���� ������ ���� - ���� ����
	output.diffuse = dot(-LightDir, worldNormal);
	output.position = mul(output.position, view);
	output.position = mul(output.position, projection);

	output.uv = input.uv;


	return output;
}