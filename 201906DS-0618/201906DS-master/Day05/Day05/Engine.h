#pragma once
#include <vector>
#include "Map.h"

class Engine
{
public:
	Engine();
	virtual ~Engine();

	virtual bool Init();
	virtual bool Term();
	virtual bool Run();

	//입력 클래스, 게임 입력 1개, 디자인 패턴, Singleton
	static int CurrentKeyCode;

	const static int LEFT = 75;      // 좌측방향키 
	const static int RIGHT = 77;      // 우측방향키 
	const static int UP = 72;      // 위쪽방향키 
	const static int DOWN = 80;      // 아래방향키

protected:
	bool bIsRunning;

	virtual void Input();
	virtual void Tick();
	virtual void Render();

	virtual bool GameLoop();


	std::vector<class Character*> Characters;

	class Map* MapData;
};
