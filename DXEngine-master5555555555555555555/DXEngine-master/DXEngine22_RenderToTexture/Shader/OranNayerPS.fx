struct ps_input
{
    float4 position      : SV_POSITION;
    float2 texCoord      : TEXCOORD0;
    float3 normal        : TEXCOORD1;
    float3 lightPosition : TEXCOORD2;
    float3 viewPosition  : TEXCOORD3;
};

// �ؽ�ó / ���÷� ������Ʈ.
Texture2D diffuseMap;
SamplerState diffuseSampler;

// �ȼ� ���̴�.
float4 main(ps_input input) : SV_TARGET
{
	//����Ʈ ���� 
    float3 lightDir = normalize(input.position.xyz - input.lightPosition);
	//��  ����
    float3 viewDir = normalize(input.position.xyz - input.viewPosition);
	//��ĥ�� ( �����Ͻ� 0 ~ 1 ���� ��)
    float roughness = 0.2f;
    float PI = 1.0f;

	//��ǻ�� ���
    float roughness2 = roughness * roughness;
    float3 normal = normalize(input.normal);

    float A = 1.0f - 0.5f * (roughness2 / (roughness2 + 0.33f));
    float B = 0.45f * (roughness2 / (roughness2 + 0.09f));

	//LdotN
    float LdotN = dot(-lightDir, normal);
	//VdotN
    float VdotN = dot(-viewDir, normal);

	//������Ų�� ( x,y ������� x : tangent , y : binormal )
    float3 lightProjection = normalize(-lightDir - normal * LdotN);
    float3 viewProjection = normalize(-viewDir - normal * VdotN);

	//����Ʈ ���� ���Ϳ� �� ���� ���� ������ �ڻ��� ���� ���
    float C = saturate(dot(lightProjection, viewProjection)); // 0���ϰ� ¥��
    //float C = max(0, dot(lightProjection, viewProjection)); // 0���ϰ� ¥��

	// theta_i
    float incidentAngle = acos(LdotN);

	// theta_r
    float viewAngle = acos(VdotN);

	//Alpha , Beta
    float Alpha = max(incidentAngle, viewAngle);
    float Beta = min(incidentAngle, viewAngle);

    float D = sin(Alpha) * tan(Beta);
   
	LdotN = saturate(LdotN); // 0���� �� ¥��

    float Albedo = 1.0f;
    float coe = Albedo / PI;

    float3 OranNayerDiffuse = coe * LdotN * (A + B * C * D); //��ǻ�� ���� �ȴ�

    float3 texColor = diffuseMap.Sample(diffuseSampler, input.texCoord).rgb;

	OranNayerDiffuse *= texColor;

    return float4(OranNayerDiffuse, 1.0f);

}