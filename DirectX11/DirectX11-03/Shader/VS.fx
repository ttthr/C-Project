//정점 셰이더
//SV_POSITION (시스템 밸류 -> 넣어줘야 하는 값)
//
//float4 main(float4 pos : POSITION) : SV_POSITION
//{
//	return pos;
//}
struct VS_INPUT
{
	float4 position : POSITION;
	float4 color : COLOR;
};
struct VS_OUTPUT
{
	float4 position : SV_POSITION;
	float4 color : COLOR;

};
VS_OUTPUT main(VS_INPUT input)
{
	VS_OUTPUT output;
	output.position = input.position;
	output.color = input.color;

	return output;
}