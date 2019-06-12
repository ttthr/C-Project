#pragma once
#include<iostream>

class CPlayer
{
public:
	CPlayer();
	~CPlayer();
private:
	int Str;
	int Dex;
	int Wiz;
	int Luck;
	int Attack;
	int Hp;
	char* name;
	int speed;
public:
	int GetStr() { return Str; }
	int GetDex() { return Dex; }
	int GetWiz() { return Wiz; }
	int GetLuck() { return Luck; }
	int GetAttack() { return Attack; }
	int GetHp() { return Hp; }
	int GetSpeed() { return speed; }
	char* GetName() { return name; }
public:
	void Move();
};

