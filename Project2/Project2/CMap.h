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
						{ 1,0,0,0,0,0,0,0,0,2 },
						{ 1,0,0,0,0,0,0,0,0,1 },
						{ 1,0,0,0,0,0,0,0,0,1 },
						{ 1,0,0,0,0,0,0,0,0,1 },
						{ 1,0,0,0,0,0,0,0,0,1 },
						{ 1,0,0,0,0,0,0,0,0,1 },
						{ 1,0,0,0,0,0,0,0,0,1 },
						{ 1,0,0,0,0,0,0,0,0,1 },
						{ 1,1,1,1,1,1,1,1,1,1 },
				      };
public:
	CPlayer* m_pPlayer;
public:
	void Init(CPlayer* _pPlayer);
	void Tick(int _KeyInput);
	void Draw();
};

