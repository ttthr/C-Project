//ÇÈ¼¿ ¼ÎÀÌ´õ

//float4 main(float4 pos : POSITION) : SV_TARGET
//{
//	return float4(1.0f,0.0f,0.0f,1.0f); 
//}

//Á¤Á¡ ¼ÎÀÌ´õÀÇ Ãâ·ÂÀÌ ÇÈ¼¿ ¼ÎÀÌ´õÀÇ ÀÔ·Â
//struct PS_INPUT
//{
//	float4 position : SV_POSITION;
//	float4 color : COLOR;
//	
//};
//
//float4 main(PS_INPUT input) : SV_TARGET
//{
//	return input.color;
//}
Texture2D DiffuseMap;
SamplerState DiffuseSampler;


struct PS_INPUT
{
	float4 position : SV_POSITION;
	//float4 color : COLOR;
	float2 uv : TEXCORD0;
};

float4 main(PS_INPUT input) : SV_TARGET
{
	float4 textureColor = DiffuseMap.Sample(DiffuseSampler, input.uv);
	
	return textureColor;
}
