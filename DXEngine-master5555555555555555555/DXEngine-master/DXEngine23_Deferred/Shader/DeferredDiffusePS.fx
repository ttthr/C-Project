struct ps_input
{
	float4 position : SV_POSITION;
	float2 texCoord : TEXCOORD;
    float3 lightDir : TEXCOORD1;
   //float3 viewDir  : TEXCOORD2; //����ŧ���Ϸ���
};

// �ؽ�ó / ���÷� ������Ʈ.
Texture2D AlbedoTextureMap : register(t0);
Texture2D normalTextureMap : register(t1);
SamplerState Sampler;

// �ȼ� ���̴�.
float4 main(ps_input input) : SV_TARGET
{
  
    float4 albedo = AlbedoTextureMap.Sample(Sampler, input.texCoord);
    float4 normal = normalTextureMap.Sample(Sampler, input.texCoord);

    float3 lightDir = normalize(input.lightDir);
    float3 diffuse = 0;
    //a�� 0�̶�°��� �׸������� ���ٴ� ����.(���ĸ� �о����� ��� �κи� 0�̰� , �������� Ŭ���� ����Ÿ���Ҷ� ���İ��� 1�� ��� ������ �������´� 1�̴�)

    if (normal.a == 0) 
    {
        diffuse = dot(lightDir, normal.rgb) * 0.5f + 0.5f; //���� ����Ʈ
        diffuse *= albedo;

    }
	
    return float4(diffuse, 1.0f);
}