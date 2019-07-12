struct ps_input
{
	float4 position : SV_POSITION;
	float2 texCoord : TEXCOORD0;
	float3 diffuse : TEXCOORD1;
};

// 텍스처 / 샘플러 스테이트.
Texture2D WarpMap : register(t0);
Texture2D diffuseMap : register(t1);
SamplerState diffuseSampler : register(s0);

// 픽셀 셰이더.
float4 main(ps_input input) : SV_TARGET
{
	// 텍스쳐 좌표 만들기
	//input.diffuse = saturate(input.diffuse);
	float2 uv = input.texCoord;

	input.diffuse = input.diffuse * 0.5f + 0.5f;

	// 넘어온 diffuse 값은 정수 하나 값. ( 그러니 넣는게 가능 )
	input.texCoord = float2(input.diffuse.x ,0.5f);
	// 텍스처 색상 읽어오기.
	
	float4 warpColor = WarpMap.Sample(diffuseSampler, input.texCoord);
	float4 textureColor = diffuseMap.Sample(diffuseSampler, uv);

	float3 result = (textureColor * warpColor);

	return float4(result.rgb, 1.0f);
}