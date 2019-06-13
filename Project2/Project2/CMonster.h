#pragma once
#include<iostream>

class CUtility;

class CMonster
{
public:
	CMonster();
	virtual ~CMonster();
protected:
	int Str;
	int Dex;
	int Wiz;
	int Luck;
	int Attack;
	int Hp;
	char name[20];
	int speed;
	int m_x;
	int m_y;
public:
	int GetStr() { return Str;}
	int GetDex() { return Dex; }
	int GetWiz() { return Wiz; }
	int GetLuck() { return Luck; }
	int GetAttack() { return Attack; }
	int GetHp() { return Hp; }
	int GetSpeed() { return speed; }
	char* GetName() { return name; }
	int GetXPos() { return m_x; }
	int GetYPos() { return m_y; }
public:
	virtual void Move();
	void Tick(int _KeyInput);
	virtual void Draw();
};

