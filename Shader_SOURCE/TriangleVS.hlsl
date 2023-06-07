
// VSIn�� ���ؽ����̴��� ������ ����.(����������)
struct VSIn
{
	float3 Pos : POSITION;
	float4 Color : COLOR;
};

// VSOut�� ������ ������. 
struct VSOut
{
	// SV_POSITION�� ������ float4�� ���������. 3���� �ϴϱ� ��������.
	float4 Pos : SV_Position;
	float4 Color : COLOR;
};

cbuffer Transform : register(b0)
{
    float4 Pos;
}

VSOut main(VSIn In) 
{
	// 0.0f�� ��簪 �ʱ�ȭ.
	VSOut Out = (VSOut)0.0f;

	Out.Pos = float4(In.Pos, 1.0f);
    Out.Pos.x += Pos.x;
    Out.Pos.y += Pos.y;
	
    Out.Color = In.Color;

	return Out;
}