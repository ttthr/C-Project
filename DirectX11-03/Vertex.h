#pragma once

#include "DXUtility.h"

using namespace DirectX;

struct Vertex
{
	XMFLOAT3 xmPosition;
	//XMFLOAT4 xmColor;
	XMFLOAT2 xmUV;
	XMFLOAT3 xmNormal;
	Vertex(){}
	Vertex(float x, float y, float z) :
		xmPosition(x, y, z) {}
	Vertex(XMFLOAT3 pos) : xmPosition(pos) {}
	//Vertex(XMFLOAT3 pos, XMFLOAT4 color) : xmPosition(pos), xmColor(color) {}
	Vertex(XMFLOAT3 pos, XMFLOAT2 uv) : xmPosition(pos), xmUV(uv) {}

};
