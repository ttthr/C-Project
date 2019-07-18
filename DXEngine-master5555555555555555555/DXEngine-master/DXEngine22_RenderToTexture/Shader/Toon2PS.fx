// ÇÈ¼¿ ¼ÎÀÌ´õ/½¦ÀÌ´õ ÀÔ·Â.
// ¼ÎÀÌ´õ/½¦ÀÌ´õ(Shader).
struct ps_input
{
	float4 position : SV_POSITION;
	float2 texCoord : TEXCOORD0;
	float3 diffuse : TEXCOORD1;
};

// ÅØ½ºÃ³ / »ùÇÃ·¯ ½ºÅ×ÀÌÆ®.
Texture2D diffuseMap;
SamplerState diffuseSampler;

// ÇÈ¼¿ ¼ÎÀÌ´õ.
float4 main(ps_input input) : SV_TARGET
{
	// ÅØ½ºÃ³ »ö»ó ÀÐ¾î¿À±â.
	float4 textureColor = diffuseMap.Sample(diffuseSampler, input.texCoord);

	// À½¿µÃ³¸® (µðÇ»Áî).
	//float3 diffuse = saturate(input.diffuse); //// 0~1»çÀÌ
	float3 diffuse = input.diffuse; // -1~ 1 »çÀÌ
	diffuse = diffuse * textureColor.rgb;

	float3 pink = float3(1.0f, 0.0f, 1.0f);
	float3 white = float3(1.0f, 1.0f, 1.0f);
	float3 black = float3(0.0f, 0.0f, 0.0f);

	float3 toon = 0;
	
	if (diffuse.x > 0)
	{
		toon = pink;
	}
	else if (diffuse.x > -0.7f)
	{
		toon = white;
	}
	else
	{
		toon = black;
	}

	return float4(toon, 1.0f);
}