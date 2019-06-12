#pragma once
#include<iostream>
class CUtility;

class CPlayer
{
public:
	CPlayer();
	~CPlayer();
private:
	const static int left = 75;
	const static int right = 77;
	const static int up = 72;
	const static int down = 80;
public:
	int x;
	int y;
public:
	void Move(int _KeyInput);
	void Tick(int _KeyInput);
	void Draw();
};

