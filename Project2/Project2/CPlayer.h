#pragma once
#include<iostream>

class CUtility;

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
	char name[20];
	int speed;
private:
	const static int left = 75;
	const static int right = 77;
	const static int up = 72;
	const static int down = 80;
public:
	int x = 1;
	int y = 1;
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
	void Move(int _KeyInput);
	void Tick(int _KeyInput);
	void Render();
};

