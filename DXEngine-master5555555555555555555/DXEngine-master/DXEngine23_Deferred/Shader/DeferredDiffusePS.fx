struct ps_input
{
	float4 position : SV_POSITION;
	float2 texCoord : TEXCOORD;
    float3 lightDir : TEXCOORD1;
   //float3 viewDir  : TEXCOORD2; //스펙큘러하려면
};

// 텍스처 / 샘플러 스테이트.
Texture2D AlbedoTextureMap : register(t0);
Texture2D normalTextureMap : register(t1);
SamplerState Sampler;

// 픽셀 셰이더.
float4 main(ps_input input) : SV_TARGET
{
  
    float4 albedo = AlbedoTextureMap.Sample(Sampler, input.texCoord);
    float4 normal = normalTextureMap.Sample(Sampler, input.texCoord);

    float3 lightDir = normalize(input.lightDir);
    float3 diffuse = 0;
    //a가 0이라는것은 그림파일이 들어갔다는 얘기다.(알파만 읽었을때 띄울 부분만 0이고 , 나머지는 클리어 렌더타겟할때 알파값을 1로 줬기 때문에 나머지는다 1이다)

    if (normal.a == 0) 
    {
        diffuse = dot(lightDir, normal.rgb) * 0.5f + 0.5f; //하프 램버트
        diffuse *= albedo;

    }
	
    return float4(diffuse, 1.0f);
}