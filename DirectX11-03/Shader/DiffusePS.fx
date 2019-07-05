Texture2D DiffuseMap;
SamplerState DiffuseSampler;


struct PS_INPUT
{
	float4 position : SV_POSITION;
	float2 uv : TEXCOORD0;
	float3 diffuse : TEXCOORD1;
};

float4 main(PS_INPUT input) : SV_TARGET
{
	//�ؽ��� ���� �о����
	float4 textureColor = DiffuseMap.Sample(DiffuseSampler, input.uv);

	//����ó�� ( ��ǻ��)
	float3 diffuse1 = saturate(input.diffuse);
	diffuse1 = diffuse * textureColor.rgb;

	return float4(diffuse1, 1.0f);
}
