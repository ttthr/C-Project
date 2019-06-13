#include "Engine.h"
#include "CPlayer.h"
#include "CMap.h"
#include "CUtility.h"
#include "CMonster.h"

CEngine::CEngine()
{
	cout << "Engine 생성자 불림" << endl;
}

CEngine::~CEngine()
{
	if (m_map != NULL)
	{
		delete m_map;
		m_map = NULL;
	}

	cout << "Engine 소멸자 불림" << endl;
}
void CEngine::Init(CPlayer * _pPlayer, CMonster* _pMonster,  CMap * _pMap)
{
	m_map = _pMap;
	m_map->Init(_pPlayer);
	m_map->InitMonster(_pMonster);
}

void CEngine::Run()
{
	while (bIsRunning)
	{
		int keyInput = Input();
		Tick(keyInput);
		Render();

	} 
}

void CEngine::Render()
{
	system("cls");
	m_map->Render();
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
