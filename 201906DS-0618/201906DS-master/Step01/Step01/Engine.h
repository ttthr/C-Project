#pragma once
#include <vector>

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

	std::vector<class Character*> characters;

	int monsterCount = 10;
};

