struct ps_input
{
	float4 position : SV_POSITION;
	float3 texCoord : TEXCOORD0;
};

// �ؽ�ó / ���÷� ������Ʈ.
TextureCube  CubeMapTexture;
SamplerState CubeMapSampler;

// �ȼ� ���̴�.
float4 main(ps_input input) : SV_TARGET
{
	float3 environment = CubeMapTexture.Sample(CubeMapSampler, input.texCoord).rgb;

	return float4(environment, 1.0f);
}