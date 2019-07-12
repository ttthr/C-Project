struct ps_input
{
	float4 position   : SV_POSITION;
	float2 texCoord   : TEXCOORD0;
	float3 lightDir   : TEXCOORD1;
	float3 viewDir    : TEXCOORD2;
	float3 normal     : TEXCOORD3;  //Z
	float3 tangent    : TEXCOORD4;  //X
	float3 binormal   : TEXCOORD5;  //Y
};
// 텍스처 / 샘플러 스테이트.

Texture2D diffuseMap : register(t0);
Texture2D normalMap: register(t1);
SamplerState diffuseSampler : register(s0);

//노멀 매핑 상위 버전?
//패럴랙스 매핑
//패럴랙스 오클루디드 매핑

float4 main(ps_input input) : SV_TARGET
{
	//변환 행렬( xyz순)
	//탄젠트 공간
	float3x3 TBN = float3x3(
		normalize(input.tangent),
		normalize(input.binormal),
		normalize(input.normal)
		);

	//탄젠트 노멀 읽어오기
	float3 tangentNormal = normalMap.Sample(diffuseSampler, input.texCoord).rgb;
	//원래 좌표값 구하기
	tangentNormal = tangentNormal * 2 - 1;
	//전치행렬 만들어서 곱해주기
	//탄젠트 공간에서 -> 월드좌표로 옴겨주기
	float3 worldNormal = mul(tangentNormal, transpose(TBN));
	worldNormal = normalize(worldNormal);

	//난반사 ( 디퓨즈 ) 구하기
	//하프 램버트공식
	//리플렉션안구하고 하프벡터 구해서 조명계산
	float3 texColor = diffuseMap.Sample(diffuseSampler, input.texCoord).rgb;
	float3 lightDir = input.lightDir;
	float3 diffuse = dot(-lightDir , worldNormal) * 0.5f + 0.5f;
	
	//조명이랑 텍스쳐 색상값
	//diffuse *= texColor;

	//스패큘러(정반사) 구하기
	float3 specular = 0;
	float3 viewDir = normalize(input.viewDir);
	float3 halfVector = (-lightDir) + (-viewDir);

	float Glossiness = 10.0f;

	//diffuse 값은 xyz 다 같은 값이 나온다.
	if (diffuse.x > 0)
	{
		float3 hdotn = dot(halfVector, worldNormal);
		specular = pow(saturate(hdotn), Glossiness * Glossiness);
	}
	//조명이랑 텍스쳐 색상값
	//specular *= texColor;

	return float4(diffuse + specular, 1.0f);
	
}