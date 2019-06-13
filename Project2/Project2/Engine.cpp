#include "Engine.h"
#include "CPlayer.h"
#include "CMap.h"
#include "CUtility.h"

CEngine::CEngine()
{
}

CEngine::~CEngine()
{
	if (m_map)
		delete m_map;
}
void CEngine::Init(CPlayer * _pPlayer, CMap * _pMap)
{
	m_map = _pMap;
	m_map->Init(_pPlayer);

}

void CEngine::Run()
{
	while (bIsRunning)
	{
		int keyInput = Input();
		Tick(keyInput);
		Draw();

	}

}

void CEngine::Draw()
{
	system("cls");
	m_map->Draw();
}

void CEngine::Tick(int _KeyInput)
{

	switch (_KeyInput)
	{
	case 'Q':
	{
		bIsRunning = false;
		break;
	}
	case 'q':
	{
		bIsRunning = false;
		break;
	}
	}
	m_map->Tick(_KeyInput);

}

int CEngine::Input()
{

	int KeyInput = getch();

	return KeyInput;
}
