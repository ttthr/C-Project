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
	int x;
	int y;
public:
	int GetStr() { return Str; }
	int GetDex() { return Dex; }
	int GetWiz() { return Wiz; }
	int GetLuck() { return Luck; }
	int GetAttack() { return Attack; }
	int GetHp() { return Hp; }
	int GetSpeed() { return speed; }
	char* GetName() { return name; }
	int GetX() { return x; }
	int GetY() { return y; }
public:
	void Move(int _KeyInput);
	int  Attack();
};
int Re()
{

}
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
	int GetStr() { return Str; }
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
	virtual int Attack();
};
class CGoblin :
	public CMonster
{
public:
	CGoblin();
	virtual ~CGoblin();
public:
	virtual void Move();
	virtual int Attack();
};
class CSlime :
	public CMonster
{
public:
	CSlime();
	virtual ~CSlime();
public:
	virtual void Move();
	virtual int Attack();

};

class CWildpig :
	public CMonster
{
public:
	CWildpig();
	virtual ~CWildpig();
public:
	virtual void Move();
	virtual int Attack();
};
