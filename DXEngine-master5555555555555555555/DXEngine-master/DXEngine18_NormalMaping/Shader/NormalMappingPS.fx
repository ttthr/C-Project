struct ps_input
{
	float4 position   : SV_POSITION;
	float2 texCoord   : TEXCOORD0;
	float3 lightDir   : TEXCOORD1;
	float3 viewDir    : TEXCOORD2;
	float3 normal     : TEXCOORD3;  //Z
	float3 tangent    : TEXCOORD4;  //X
	float3 binormal   : TEXCOORD5;  //Y
};
// �ؽ�ó / ���÷� ������Ʈ.

Texture2D diffuseMap : register(t0);
Texture2D normalMap: register(t1);
SamplerState diffuseSampler : register(s0);

//��� ���� ���� ����?
//�з����� ����
//�з����� ��Ŭ���� ����

float4 main(ps_input input) : SV_TARGET
{
	//��ȯ ���( xyz��)
	//ź��Ʈ ����
	float3x3 TBN = float3x3(
		normalize(input.tangent),
		normalize(input.binormal),
		normalize(input.normal)
		);

	//ź��Ʈ ��� �о����
	float3 tangentNormal = normalMap.Sample(diffuseSampler, input.texCoord).rgb;
	//���� ��ǥ�� ���ϱ�
	tangentNormal = tangentNormal * 2 - 1;
	//��ġ��� ���� �����ֱ�
	//ź��Ʈ �������� -> ������ǥ�� �Ȱ��ֱ�
	float3 worldNormal = mul(tangentNormal, transpose(TBN));
	worldNormal = normalize(worldNormal);

	//���ݻ� ( ��ǻ�� ) ���ϱ�
	//���� ����Ʈ����
	//���÷��Ǿȱ��ϰ� �������� ���ؼ� ������
	float3 texColor = diffuseMap.Sample(diffuseSampler, input.texCoord).rgb;
	float3 lightDir = input.lightDir;
	float3 diffuse = dot(-lightDir , worldNormal) * 0.5f + 0.5f;
	
	//�����̶� �ؽ��� ����
	//diffuse *= texColor;

	//����ŧ��(���ݻ�) ���ϱ�
	float3 specular = 0;
	float3 viewDir = normalize(input.viewDir);
	float3 halfVector = (-lightDir) + (-viewDir);

	float Glossiness = 10.0f;

	//diffuse ���� xyz �� ���� ���� ���´�.
	if (diffuse.x > 0)
	{
		float3 hdotn = dot(halfVector, worldNormal);
		specular = pow(saturate(hdotn), Glossiness * Glossiness);
	}
	//�����̶� �ؽ��� ����
	//specular *= texColor;

	return float4(diffuse + specular, 1.0f);
	
}