#pragma once
#include<iostream>

class CPlayer;
class CMonster;

class CMap
{
public:
	CMap();
	~CMap();
public:
	int map[10][10] = { { 1,1,1,1,1,1,1,1,1,1 },
						{ 1,0,0,0,0,0,0,0,0,1 },
						{ 1,0,0,0,0,0,0,0,0,1 },
						{ 1,0,0,0,0,0,0,0,0,1 },
						{ 1,0,0,0,0,0,0,0,0,1 },
						{ 1,0,0,0,0,0,0,0,0,1 },
						{ 1,0,0,0,0,0,0,0,0,1 },
						{ 1,0,0,0,0,0,0,0,0,1 },
						{ 1,0,0,0,0,0,0,0,0,1 },
						{ 1,1,1,1,1,1,1,1,1,2 },
				      };
public:
	CPlayer* m_pPlayer;
	CMonster* m_pMonster;
public:
	void Init(CPlayer* _pPlayer);
	void InitMonster(CMonster* _pMonster);
	void Tick(int _KeyInput);
	void Render();
};

