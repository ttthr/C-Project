#include "CEngine.h"

CEngine::CEngine()
	
{
	Init(); //�ʱ�ȭ
}

CEngine::~CEngine()
{
	Term(); // ����
}

bool CEngine::Init()
{
	bIsRunning = true; 
	return true;
}

bool CEngine::Run()
{
	return GameLoop(); 
}

bool CEngine::Term()
{
	return false;
}

int CEngine::input()
{
	return 0;
}

void CEngine::Tick()
{

}


void CEngine::Render()
{

}

bool CEngine::GameLoop()
{
	while (bIsRunning)
	{
		input();
		Tick();
		Render();
	}
	return false;
}

