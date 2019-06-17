#pragma once
#include"Define.h"
#include "CCharacter.h"
#include "CPlayer.h"
#include "CMonster.h"
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
	vector<CCharacter*> m_Characters;
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
	void SetCharacters(vector<CCharacter*> _m_Characters);
	void Render();
};

