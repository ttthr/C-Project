#include "CUtility.h"

CUtility::CUtility()
{


}

CUtility::~CUtility()
{


}

int CUtility::clamp(int Current, int Min, int Max)
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
