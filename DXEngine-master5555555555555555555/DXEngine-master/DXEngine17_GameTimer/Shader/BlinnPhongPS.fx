struct ps_input
{
	float4 position   : SV_POSITION;
	float2 texCoord   : TEXCOORD0;
	float3 diffuse    : TEXCOORD1;
	float3 halfVector : TEXCOORD2;
	float3 normal     : NORMAL;
};
// 텍스처 / 샘플러 스테이트.

Texture2D diffuseMap;
SamplerState diffuseSampler;

float4 main(ps_input input) : SV_TARGET0
{

	//텍스쳐 샘플링
	float4 texColor = diffuseMap.Sample(diffuseSampler, input.texCoord);

	//half 램버트 공식
	float3 diffuse = input.diffuse * 0.5f + 0.5f;
	//텍스쳐 값이 음영이랑 합쳐진다.
	diffuse *= texColor.rgb;

	//노멀라이즈 한번 해준다.
	float3 halfVector = normalize(input.halfVector);
	float3 normal = normalize(input.normal);

	//스펙큘러 처리
	float3 specular = 0;

	//빛의 강도가 0보다 클 때만 계산
	if (diffuse.x > 0)
	{
		float3 hDotn = dot(halfVector, normal);
		specular = saturate(hDotn);
		specular = pow(specular, 100.0f);
	}
	specular *= texColor.rgb;

	return float4(diffuse + specular, 1.0f);
}