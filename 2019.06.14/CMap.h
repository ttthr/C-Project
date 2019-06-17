#pragma once
#include"Define.h"
#include "CCharacter.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CActor.h"
#include "CUtility.h"
class Vector;

class CMap 
	: public CActor
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
						 { 1,2,0,1,0,0,0,0,0,1 },
						 { 1,0,0,1,0,0,0,0,0,1 },
						 { 1,0,0,1,0,0,0,0,0,1 },
						 { 1,0,0,1,0,0,0,0,0,1 },
						 { 1,0,0,0,0,0,0,0,0,1 },
						 { 1,0,0,0,0,0,0,0,0,1 },
						 { 1,0,0,0,0,0,0,0,0,1 },
						 { 1,0,0,0,0,0,0,0,9,1 },
						 { 1,1,1,1,1,1,1,1,1,1 },
	
	};
public:
	void SetCharacters(vector<CCharacter*> _m_Characters);
	virtual void Tick()override;
	virtual void Render() override;
	char GetMapTile(int _Type);
public:
	//수업시간
	Vector FindPlayerPosition();
	Vector FindMonsterPosition();
};

