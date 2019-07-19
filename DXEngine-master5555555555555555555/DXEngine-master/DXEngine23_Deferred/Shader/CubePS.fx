struct ps_input
{
	float4 position : SV_POSITION;
	float3 texCoord : TEXCOORD0;
};

// 텍스처 / 샘플러 스테이트.
TextureCube  CubeMapTexture;
SamplerState CubeMapSampler;

// 픽셀 셰이더.
float4 main(ps_input input) : SV_TARGET
{
	float3 environment = CubeMapTexture.Sample(CubeMapSampler, input.texCoord).rgb;

	return float4(environment, 1.0f);
}