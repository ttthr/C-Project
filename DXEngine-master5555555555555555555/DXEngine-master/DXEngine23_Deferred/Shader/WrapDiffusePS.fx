struct ps_input
{
	float4 position : SV_POSITION;
	float2 texCoord : TEXCOORD0;
	float3 diffuse : TEXCOORD1;
};

// �ؽ�ó / ���÷� ������Ʈ.
Texture2D WarpMap : register(t0);
Texture2D diffuseMap : register(t1);
SamplerState diffuseSampler : register(s0);

// �ȼ� ���̴�.
float4 main(ps_input input) : SV_TARGET
{
	// �ؽ��� ��ǥ �����
	//input.diffuse = saturate(input.diffuse);
	float2 uv = input.texCoord;

	input.diffuse = input.diffuse * 0.5f + 0.5f;

	// �Ѿ�� diffuse ���� ���� �ϳ� ��. ( �׷��� �ִ°� ���� )
	input.texCoord = float2(input.diffuse.x ,0.5f);
	// �ؽ�ó ���� �о����.
	
	float4 warpColor = WarpMap.Sample(diffuseSampler, input.texCoord);
	float4 textureColor = diffuseMap.Sample(diffuseSampler, uv);

	float3 result = (textureColor * warpColor);

	return float4(result.rgb, 1.0f);
}