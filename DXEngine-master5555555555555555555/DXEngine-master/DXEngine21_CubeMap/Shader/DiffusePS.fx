struct ps_input
{
	float4 position : SV_POSITION;
	float2 texCoord : TEXCOORD0;
	float3 diffuse : TEXCOORD1;
};

// �ؽ�ó / ���÷� ������Ʈ.
Texture2D diffuseMap;
SamplerState diffuseSampler;

// �ȼ� ���̴�.
float4 main(ps_input input) : SV_TARGET
{
	// �ؽ�ó ���� �о����.
	float4 textureColor = diffuseMap.Sample(diffuseSampler, input.texCoord);

	// ����ó�� (��ǻ��).����Ʈ
	//float3 diffuse = saturate(input.diffuse);
	//���� ����Ʈ
	float3 diffuse = (input.diffuse);
	diffuse = diffuse * 0.5f + 0.5f;
	diffuse = pow(diffuse, 3.0f);
	diffuse = diffuse * textureColor.rgb;

	return float4(diffuse, 1.0f);
}