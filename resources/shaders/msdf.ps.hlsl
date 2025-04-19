cbuffer CONSTANT_DATA : register(b0)
{
    float unused; // inherited from cb_pixel
	float2 glyphPos;
	float2 glyphSize;
};

struct PS_INPUT
{
    float4 inPos : SV_POSITION;
    float4 inColor : COLOR;
    float2 inTexCoord : TEXCOORD;
};

Texture2D tex : TEXTURE : register(t0);
SamplerState sam : SAMPLER : register(s0);

float median(float x, float y, float z)
{
    return max(min(x, y), min(max(x, y), z));
}

float screenPxRange()
{
	
}

float4 main(PS_INPUT input) : SV_TARGET
{
    float3 msd = tex.Sample(sam, input.inTexCoord);
    float sd = median(msd.x, msd.y, msd.z);
	//float range = 
	return float4(0, 0, 0, 0);
}