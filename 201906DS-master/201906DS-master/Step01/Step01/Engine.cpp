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

	player = new Player();
	for (int i = 0; i < 10; ++i)
	{
		int type = rand() % 3;
		switch (type)
		{
			case 0:
				monster[i] = new Slime();
				break;
			case 1:
				monster[i] = new Goblin();
				break;
			case 2:
				monster[i] = new Wildboar();
				break;
		}
		
	}
}

void Engine::Term()
{
	delete player;
	player = nullptr;

	for (int i = 0; i < 10; ++i)
	{
		delete monster[i];
		monster[i] = nullptr;
	}
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

	player->Move();
	for (int i = 0; i < 10; ++i)
	{
		monster[i]->Move();
	}
}

void Engine::Render()
{
}
