#include "CMap.h"
#include "CPlayer.h"
#include "CMonster.h"


CMap::CMap()
{

}

CMap::~CMap()
{
	if (m_pPlayer != NULL)
	{
		delete m_pPlayer;
		m_pPlayer = NULL;
	}
	if (m_pMonster != NULL)
	{
		delete m_pMonster;
		m_pMonster = NULL;
	}
}

void CMap::Init(CPlayer * _pPlayer)
{
	m_pPlayer = _pPlayer;
}

void CMap::InitMonster(CMonster * _pMonster)
{
	m_pMonster = _pMonster;
}

void CMap::Tick(int _KeyInput)
{
	m_pPlayer->Tick(_KeyInput);
	m_pMonster->Tick(_KeyInput);
}

void CMap::Render()
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (i == m_pPlayer->x && j == m_pPlayer->y)
				m_pPlayer->Render();
			//if (i == m_pMonster->GetXPos() && j == m_pMonster->GetYPos())
				//m_pMonster->Draw();
			else
				std::cout << map[i][j];

		}
		std::cout << std::endl;
	}
	m_pMonster->Render();

}
