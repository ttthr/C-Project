#include "CMap.h"

CMap::CMap()
{



}

CMap::~CMap()
{



}
int CMap::clamp(int Current, int Min, int Max)
{
	if (Current < Min)
	{
		return Min;
	}
	if (Current > Max)
	{
		return Max;
	}

	return Current;
}

