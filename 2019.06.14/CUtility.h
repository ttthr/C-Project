#pragma once
#include "Define.h"

class CUtility
{
public:
	CUtility();
	~CUtility();
public:
	static void SetXY(int _x, int _y);
	static void SetObject(char c);
	static void SetObject(int c);
	static void SetTextColor(int foreground, int background);
	static int  clamp(int Current, int Min, int Max);
};

