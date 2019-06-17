#include "CUtility.h"

CUtility::CUtility()
{


}

CUtility::~CUtility()
{


}
void CUtility::SetXY(int _x, int _y)
{
	COORD cur;
	cur.X = _x;
	cur.Y = _y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);

}

void CUtility::SetObject(char c)
{
	cout << c;
}

void CUtility::SetObject(int c)
{
	cout << c;
}

void CUtility::SetTextColor(int foreground, int background)
{
	int color = foreground * background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

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
