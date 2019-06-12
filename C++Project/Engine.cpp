#include "Engine.h"
#include "CPlayer.h"
#include "CMap.h"
#include "CUtility.h"

CEngine::CEngine()
{
	/*m_pPlayer = new CPlayer;
	m_map = new CMap;
	m_Utility = new CUtility;*/
}

CEngine::~CEngine()
{
	/*if (m_pPlayer)
		delete m_pPlayer;
	if (m_map)
		delete m_map;
	if (m_Utility)
		delete m_Utility;*/
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

	/*for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (i == m_pPlayer->x && j == m_pPlayer->y)
				cout << "@";
			else
				cout << m_map->map[i][j];

		}
		cout << endl;
	}*/

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

	/*switch (_KeyInput)
	{
	case RIGHT:
	{
		m_pPlayer->x++;
		break;
	}
	case LEFT:
	{
		m_pPlayer->x--;
		break;
	}
	case UP:
	{
		m_pPlayer->y--;
		break;
	}
	case DOWN:
	{
		m_pPlayer->y++;
		break;
	}
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
	default:
		break;
	}

	m_pPlayer->x = m_Utility->clamp(m_pPlayer->x, 1, 8);
	m_pPlayer->y = m_Utility->clamp(m_pPlayer->y, 1, 8);*/

}

int CEngine::Input()
{

	int KeyInput = getch();

	return KeyInput;
}
