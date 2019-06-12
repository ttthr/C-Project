#include "CMap.h"
#include "CPlayer.h"


CMap::CMap()
{

}


CMap::~CMap()
{
}

void CMap::Init(CPlayer * _pPlayer)
{
	m_pPlayer = _pPlayer;
}

void CMap::Tick(int _KeyInput)
{
	m_pPlayer->Tick(_KeyInput);
}

void CMap::Draw()
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (i == m_pPlayer->x && j == m_pPlayer->y)
				m_pPlayer->Draw();
			else
				std::cout << map[i][j];

		}
		std::cout << std::endl;
	}

}
