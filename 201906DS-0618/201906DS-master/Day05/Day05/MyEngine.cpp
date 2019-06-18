#include "MyEngine.h"
#include <stdio.h>
#include "Map.h"
#include "Player.h"
#include "Monster.h"
#include <stdlib.h>


MyEngine::MyEngine()
{
	//	Engine::Init();
	Init();
}


MyEngine::~MyEngine()
{
	Term();
	//	Engine::Term();
}

bool MyEngine::Init()
{
	printf("MyEngine Init().\n");
	MapData = new Map();
	Characters.push_back(new Player(MapData));
	Characters.push_back(new Monster(MapData));


	return true;
}

bool MyEngine::Term()
{
	for (int i = 0; i < Characters.size(); ++i)
	{
		delete Characters[i];
		Characters[i] = nullptr;
	}

	delete MapData;
	MapData = nullptr;

	printf("MyEngine Term().\n");
	return true;
}

bool MyEngine::Run()
{
	Engine::GameLoop();

	return false;
}

void MyEngine::Input()
{
	Engine::Input();

}

void MyEngine::Tick()
{
	//code here
	//Player, Monster bla bla;
	MapData->Tick();
	for (int i = 0; i < Characters.size(); ++i)
	{
		Characters[i]->Tick(); //Player, Monster
	}

	if (Characters[0]->Position.X == Characters[1]->Position.X &&
		Characters[0]->Position.Y == Characters[1]->Position.Y)
	{
		//Die
		bIsRunning = false;
		//결과 화면 추가
	}
	else if (Characters[0]->Position.X == 8 &&
		Characters[0]->Position.Y == 8)
	{
		//Escape
		bIsRunning = false;
		//결과 화면 추가
	}


	Engine::Tick();
}

void MyEngine::Render()
{
	Engine::Render();

	system("cls");

	MapData->Render();
	for (int i = 0; i < Characters.size(); ++i)
	{
		Characters[i]->Render(); //Player, Monster
	}



	Engine::Tick();
}
