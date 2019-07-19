struct ps_input
{
	float4 position : SV_POSITION;  
	float2 texCoord : TEXCOORD;
    float3 normal   : TEXCOORD1;
};

struct ps_output
{
    float4 albedo : SV_TARGET0;
    float4 normal : SV_TARGET1;
};

// 텍스처 / 샘플러 스테이트.
Texture2D diffuseMap;
SamplerState diffuseSampler;

// 픽셀 셰이더.
ps_output main(ps_input input) : SV_TARGET
{
    ps_output output;
    //색상 값을 추출해서 렌더타겟에 넣는다.
    output.albedo = diffuseMap.Sample(diffuseSampler, input.texCoord); //렌더 타겟 1번 ( 색상 값 ) 
    output.normal = float4(normalize(input.normal), 0); //렌더 타겟 2번 ( 조명 계산용 )

    return output;
}