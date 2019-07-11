struct ps_input
{
	float4 position   : SV_POSITION;
	float2 texCoord   : TEXCOORD0;
	float3 diffuse    : TEXCOORD1;
	float3 halfVector : TEXCOORD2;
	float3 normal     : NORMAL;
};
// �ؽ�ó / ���÷� ������Ʈ.

Texture2D diffuseMap;
SamplerState diffuseSampler;

float4 main(ps_input input) : SV_TARGET0
{

	//�ؽ��� ���ø�
	float4 texColor = diffuseMap.Sample(diffuseSampler, input.texCoord);

	//half ����Ʈ ����
	float3 diffuse = input.diffuse * 0.5f + 0.5f;
	//�ؽ��� ���� �����̶� ��������.
	diffuse *= texColor.rgb;

	//��ֶ����� �ѹ� ���ش�.
	float3 halfVector = normalize(input.halfVector);
	float3 normal = normalize(input.normal);

	//����ŧ�� ó��
	float3 specular = 0;

	//���� ������ 0���� Ŭ ���� ���
	if (diffuse.x > 0)
	{
		float3 hDotn = dot(halfVector, normal);
		specular = saturate(hDotn);
		specular = pow(specular, 100.0f);
	}
	specular *= texColor.rgb;

	return float4(diffuse + specular, 1.0f);
}