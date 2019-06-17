#include "CMap.h"

CMap::CMap()
{

}

CMap::~CMap()
{



}
int CMap::clamp(int Current, int Min, int Max)
{
	if (Current < Min)
	{
		return Min;
	}
	if (Current > Max)
	{
		return Max;
	}

	return Current;
}

void CMap::SetCharacters(vector<CCharacter*> _m_Characters)
{
	m_Characters = _m_Characters;
}

void CMap::Render()
{

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (i == dynamic_cast<CPlayer*>(m_Characters[0])->Position.x && j == dynamic_cast<CPlayer*>(m_Characters[0])->Position.y)
				dynamic_cast<CPlayer*>(m_Characters[0])->Render();
			else if (i == dynamic_cast<CMonster*>(m_Characters[1])->Position.x && j == dynamic_cast<CMonster*>(m_Characters[1])->Position.y)
				dynamic_cast<CMonster*>(m_Characters[1])->Render();
			else
				cout << Data[i][j];
		}
		cout << endl;
	}

}


