struct ps_input
{
	float4 position : SV_POSITION;
	float2 texCoord : TEXCOORD0;
	float3 diffuse  : TEXCOORD1;
	float3 viewDir  : TEXCOORD2;
	float3 normal   : TEXCOORD3;
};

// 텍스처 / 샘플러 스테이트.
Texture2D diffuseMap;
SamplerState diffuseSampler;

// 픽셀 셰이더.
float4 main(ps_input input) : SV_TARGET
{
	// 텍스처 색상 읽어오기.
	float4 textureColor = diffuseMap.Sample(diffuseSampler, input.texCoord);

	// 음영처리 (디퓨즈).램버트
	//float3 diffuse = saturate(input.diffuse);
	//하프 램버트 ( saturate ㄴㄴ )
	float3 diffuse = (input.diffuse);
	diffuse = diffuse * 0.5f + 0.5f;
	diffuse = pow(diffuse, 3.0f);
	diffuse = diffuse * textureColor.rgb;

	float3 normal = normalize(input.normal);
	float3 rimColor = float3(1.0f, 1.0f, 1.0f);
	//림라이트 계산
	//0이하는 짜른다 saturate
	//이방식으로 하면 최소값이 0이 나오게 되면 1.0 값이 나오기 떄문에
	//뒤가 다 밝게 나온다.
	//float3 rim = saturate(dot(-input.viewDir, normal));

	//절대값으로 처리한다.
	float3 rim = abs(dot(-input.viewDir, normal));

	//테두리만 빛나게 하려고 하는 것
	float rimLine = 2.0f;
	rim= pow(1.0f - rim, rimLine) * rimColor;

	return float4(rim + diffuse, 1.0f);
}