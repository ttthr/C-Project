//���� ���̴�
//SV_POSITION (�ý��� ��� -> �־���� �ϴ� ��)
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