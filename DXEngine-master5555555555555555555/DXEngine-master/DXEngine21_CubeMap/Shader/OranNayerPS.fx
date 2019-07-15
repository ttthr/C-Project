struct ps_input
{
    float4 position      : SV_POSITION;
    float2 texCoord      : TEXCOORD0;
    float3 normal        : TEXCOORD1;
    float3 lightPosition : TEXCOORD2;
    float3 viewPosition  : TEXCOORD3;
};

// 텍스처 / 샘플러 스테이트.
Texture2D diffuseMap;
SamplerState diffuseSampler;

// 픽셀 셰이더.
float4 main(ps_input input) : SV_TARGET
{
	//라이트 벡터 
    float3 lightDir = normalize(input.position.xyz - input.lightPosition);
	//뷰  벡터
    float3 viewDir = normalize(input.position.xyz - input.viewPosition);
	//거칠기 ( 러프니스 0 ~ 1 사이 값)
    float roughness = 0.2f;
    float PI = 1.0f;

	//디퓨즈 계산
    float roughness2 = roughness * roughness;
    float3 normal = normalize(input.normal);

    float A = 1.0f - 0.5f * (roughness2 / (roughness2 + 0.33f));
    float B = 0.45f * (roughness2 / (roughness2 + 0.09f));

	//LdotN
    float LdotN = dot(-lightDir, normal);
	//VdotN
    float VdotN = dot(-viewDir, normal);

	//투영시킨다 ( x,y 평면으로 x : tangent , y : binormal )
    float3 lightProjection = normalize(-lightDir - normal * LdotN);
    float3 viewProjection = normalize(-viewDir - normal * VdotN);

	//라이트 투영 벡터와 뷰 투영 벡터 사이의 코사인 값을 계산
    float C = saturate(dot(lightProjection, viewProjection)); // 0이하값 짜름
    //float C = max(0, dot(lightProjection, viewProjection)); // 0이하값 짜름

	// theta_i
    float incidentAngle = acos(LdotN);

	// theta_r
    float viewAngle = acos(VdotN);

	//Alpha , Beta
    float Alpha = max(incidentAngle, viewAngle);
    float Beta = min(incidentAngle, viewAngle);

    float D = sin(Alpha) * tan(Beta);
   
	LdotN = saturate(LdotN); // 0이하 값 짜름

    float Albedo = 1.0f;
    float coe = Albedo / PI;

    float3 OranNayerDiffuse = coe * LdotN * (A + B * C * D); //디퓨즈 값이 된다

    float3 texColor = diffuseMap.Sample(diffuseSampler, input.texCoord).rgb;

	OranNayerDiffuse *= texColor;

    return float4(OranNayerDiffuse, 1.0f);

}