// 상수 버퍼.
cbuffer perObjectBuffer : register(b0)
{
	matrix world;
};

cbuffer perSceneBuffer : register(b1)
{
	matrix viewProjection;
	float3 worldLightPosition;
	float3 worldCameraPosition;
};

struct vs_input
{
	float4 position : POSITION;
	float2 texCoord : TEXCOORD0;
	float3 normal   : NORMAL;
};
struct vs_output
{
	float4 position   : SV_POSITION;
	float2 texCoord   : TEXCOORD0;
	float3 diffuse    : TEXCOORD1;
	float3 halfVector : TEXCOORD2;
	float3 normal     : NORMAL;
};

vs_output main(vs_input input)
{
	vs_output output;
	//월드변환
	output.position = mul(input.position, world);
	//라이트 벡터
	//단위 벡터로 만들어 줘야함
	float3 lightDir = normalize(output.position.xyz - worldLightPosition);
	//월드 노멀
	output.normal = normalize(mul(input.normal, (float3x3)world));
	//뷰 벡터
	float3 viewDir = normalize(output.position.xyz - worldCameraPosition);
	//하프 벡터
	output.halfVector = normalize((-lightDir) + (-viewDir));
	//뷰/투영변환
	output.position = mul(output.position, viewProjection);
	//텍스쳐 좌표
	output.texCoord = input.texCoord;
	//난반사광(디퓨즈)
	// -1 ~ 1 사이 값이 나온다.
	output.diffuse = dot(-lightDir, output.normal);

	return output;
}