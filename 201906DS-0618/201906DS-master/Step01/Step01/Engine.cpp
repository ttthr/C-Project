#include "Engine.h"
#include <conio.h>
#include "Player.h"
#include <stdio.h>
#include "Slime.h"
#include "Goblin.h"
#include "Wildboar.h"
#include <stdlib.h>
#include <time.h>

Engine::Engine()
{
	printf("Engine 持失切\n");
	Init();
	bIsRunning = true;
}


Engine::~Engine()
{
	Term();
	printf("Engine 社瑚切");
}

void Engine::Init()
{
	srand((unsigned int)time(0));

	monsterCount = rand() % 5 + 1;

	characters.push_back(new Player());


	for (int i = 0; i < monsterCount; ++i)
	{
		int type = rand() % 3;
		switch (type)
		{
			case 0:
				characters.push_back(new Slime());
				break;
			case 1:
				characters.push_back(new Goblin());
				break;
			case 2:
				characters.push_back(new Wildboar());
				break;
		}
	}
}

void Engine::Term()
{
//	delete player;
	//player = nullptr;

	for (int i = 0; i < characters.size(); ++i)
	{
		delete characters[i];
		characters[i] = nullptr;
	}

	characters.clear();
}

void Engine::Run()
{
	while (bIsRunning)
	{
		int KeyCode =  Input();
		Tick(KeyCode);
		Render();
	}
}

int Engine::Input()
{
	int KeyCode = getch();

	return KeyCode;
}

void Engine::Tick(int KeyCode)
{
	if (KeyCode == 'Q' || KeyCode == 'q')
	{
		bIsRunning = false;
	}

	for (int i = 0; i < characters.size(); ++i)
	{
		characters[i]->Move();
	}
}

void Engine::Render()
{
}
