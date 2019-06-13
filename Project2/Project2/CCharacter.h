#pragma once
#include<iostream>
using namespace std;

class CCharacter
{
public:
	CCharacter();
	~CCharacter();
protected:
	int x;
	int y;
	int Str;
	int Dex;
	int Int;
	int Luk;
	int Attack;
	int Hp;
	char name[20];
	int speed;
public:
	int GetStr() { return Str; }
	int GetDex() { return Dex; }
	int GetWiz() { return Int; }
	int GetLuck() { return Luk; }
	int GetAttack() { return Attack; }
	int GetHp() { return Hp; }
	int GetSpeed() { return speed; }
	char* GetName() { return name; }
	int GetXPos() { return x; }
	int GetYPos() { return y; }
public:
	void Move();

};

