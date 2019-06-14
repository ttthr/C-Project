#pragma once
class CMap
{
public:
	CMap();
	~CMap();
public:
	enum class TYPE
	{
		EMPTY = 0,
		WALL = 1,
		STRAT = 2,
		GOAL = 9
	};
public:
	int Data[10][10] = { { 1,1,1,1,1,1,1,1,1,1 },
						 { 1,2,0,0,0,0,0,0,0,1 },
						 { 1,0,0,0,0,0,0,0,0,1 },
						 { 1,0,0,0,0,0,0,0,0,1 },
						 { 1,0,0,0,0,0,0,0,0,1 },
					 	 { 1,0,0,0,0,0,0,0,0,1 },
					     { 1,0,0,0,0,0,0,0,0,1 },
						 { 1,0,0,0,0,0,0,0,0,1 },
						 { 1,0,0,0,0,0,0,0,9,1 },
						 { 1,1,1,1,1,1,1,1,1,1 },
	};
public:
	int clamp(int Current, int Min, int Max);
};

