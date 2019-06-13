#pragma once
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

	class Player* player;
	//class Goblin* goblin[100];
	//class Wildboar* wildboar[100];
	//class Slime* slime[100];

	class Monster* monster[100];
};

