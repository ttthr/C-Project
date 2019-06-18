#include "Util.h"
#include <windows.h>
#include <stdio.h>

Util::Util()
{
}


Util::~Util()
{
}

void Util::SetXY(int X, int Y)
{
	COORD Cur;
	Cur.X = X;
	Cur.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void Util::SetObject(char C)
{
	printf("%c", C);
}

void Util::SetObject(int C)
{
	printf("%c", (char)C);
}

void Util::TextColor(int ForegroundColor, int BackgroundColor)
{
	int color = ForegroundColor + BackgroundColor * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int Util::Clamp(int Current, int Min, int Max)
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
