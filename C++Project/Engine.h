#pragma once
#include<conio.h>

class CEngine
{
public:
	CEngine();
	~CEngine();
public:
	void Run();
	void Draw();
	void Tick(int KeyInput);
	int Input();

	bool bIsRunning = true;
};
