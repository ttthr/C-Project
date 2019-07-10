struct ps_input
{
	float4 position   : SV_POSITION;
	float2 texCoord   : TEXCOORD0;
	float3 diffuse    : TEXCOORD1;
	float3 viewDir    : TEXCOORD2;
	float3 reflection : TEXCOORD3;
};

// �ؽ�ó / ���÷� ������Ʈ.
Texture2D diffuseMap;
SamplerState diffuseSampler;

// �ȼ� ���̴�.
float4 main(ps_input input) : SV_TARGET
{
	// �ؽ�ó ���� �о����.
	float4 textureColor = diffuseMap.Sample(diffuseSampler, input.texCoord);

	// ����ó�� (��ǻ��).
	// 0���ϴ� ©����.
	float3 diffuse = max(0, input.diffuse);
	//float3 diffuse = saturate(input.diffuse);
	//diffuse = diffuse * textureColor.rgb; //�ؽ��� ���� �о���� ��

	//�� ����
	//�ø� �Լ�
	//��ǻ�� ������ 0~1 ���̰� �����µ�
	//�������� ������ �ٸ��� ����� �� ó�� ���δ�.
	//x3 ���� �� /3 �ؼ� 0~1�� �����
	float3 toon = ceil(diffuse * 3) / 3;

	//�ѿ��� �� 
	float3 reflection = normalize(input.reflection);
	float3 viewDir = normalize(input.viewDir);

	//����ŧ�� ���ϱ�
	float3 specular = 0;

	//���� ������ 0���� ū ��츸 ����Ѵ�.
	// x,y,z, �� �� ���� ������ ������
	// 0���� ū ���� ���´�.
	if (diffuse.x > 0)
	{
		float3 reflectionDotviewDir = dot(reflection, -viewDir);
		//specular = saturate(reflectionDotviewDir);
		specular = max(0, reflectionDotviewDir);
		specular = pow(specular, 48.0f);
	}
	//�ݴ�� ���
	//float3 specularColor = float3(1.f, 0.0f, 0.0f);
	//specular = 1.0f - specular;
	//float3 color = (specular * specularColor);
	//return float4(color , 1.0f);

	//float4 Color = float4(diffuse,1.0f) + float4(specular,1.0f);
	//return Color;
	//return float4(diffuse, 1.0f);

	toon  = toon * textureColor.rgb;
	return float4(toon , 1.0f);
}