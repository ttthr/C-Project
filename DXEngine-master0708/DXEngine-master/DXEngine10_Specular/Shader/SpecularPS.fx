struct ps_input
{
	float4 position   : SV_POSITION;
	float2 texCoord   : TEXCOORD0;
	float3 diffuse    : TEXCOORD1;
	float3 viewDir    : TEXCOORD2;
	float3 reflection : TEXCOORD3;
};

// 텍스처 / 샘플러 스테이트.
Texture2D diffuseMap;
SamplerState diffuseSampler;

// 픽셀 셰이더.
float4 main(ps_input input) : SV_TARGET
{
	// 텍스처 색상 읽어오기.
	float4 textureColor = diffuseMap.Sample(diffuseSampler, input.texCoord);

	// 음영처리 (디퓨즈).
	// 0이하는 짤린다.
	float3 diffuse = max(0, input.diffuse);
	//float3 diffuse = saturate(input.diffuse);
	diffuse = diffuse * textureColor.rgb;

	//넘오온 값 
	float3 reflection = normalize(input.reflection);
	float3 viewDir = normalize(input.viewDir);

	//스펙큘러 구하기
	float3 specular = 0;

	//빛의 강도가 0보다 큰 경우만 계산한다.
	// x,y,z, 가 다 같은 값으로 들어오고
	// 0보다 큰 값만 들어온다.
	if (diffuse.x > 0)
	{
		float3 reflectionDotviewDir = dot(reflection, -viewDir);
		//specular = saturate(reflectionDotviewDir);
		specular = max(0, reflectionDotviewDir);
		specular = pow(specular, 48.0f);
	}
	//반대로 출력
	//float3 specularColor = float3(1.f, 0.0f, 0.0f);
	//specular = 1.0f - specular;
	//float3 color = (specular * specularColor);
	//return float4(color , 1.0f);

	float4 Color = float4(diffuse,1.0f) + float4(specular,1.0f);
	return Color;

}