#pragma once
#include <iostream>
#include <vector>
#include "Monster.h"
using namespace std;

class Engine
{
public:
	Engine();
	~Engine();

	void Init();
	void Term();
	void Run();

	int Input();
	void Tick(int KeyCode);
	void Render();

	bool bIsRunning;

	vector<Character*> characters;
	int monsterCount;
};

