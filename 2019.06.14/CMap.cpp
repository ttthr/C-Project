#include "CMap.h"
#include "Vector.h"

CMap::CMap()
{

}

CMap::~CMap()
{



}
void CMap::SetCharacters(vector<CCharacter*> _m_Characters)
{
	m_Characters = _m_Characters;
}

void CMap::Tick()
{
	//할일 생각해보기
}

void CMap::Render()
{

	for (int y = 0; y < 10; ++y)
	{
		for (int x = 0; x < 10; ++x)
		{
			CUtility::SetXY(x, y);
			CUtility::SetObject(GetMapTile(Data[y][x]));

		}
	}

	//for (int i = 0; i < 10; ++i)
	//{
	//	for (int j = 0; j < 10; ++j)
	//	{
	//		if (i == dynamic_cast<CPlayer*>(m_Characters[0])->Position.x && j == dynamic_cast<CPlayer*>(m_Characters[0])->Position.y)
	//			dynamic_cast<CPlayer*>(m_Characters[0])->Render();
	//		else if (i == dynamic_cast<CMonster*>(m_Characters[1])->Position.x && j == dynamic_cast<CMonster*>(m_Characters[1])->Position.y)
	//			dynamic_cast<CMonster*>(m_Characters[1])->Render();
	//		else
	//			cout << Data[i][j];
	//	}
	//	cout << endl;
	//}

}

char CMap::GetMapTile(int _Type)
{
	
	switch (_Type)
	{
	case 0:
	{
		CUtility::SetTextColor(WHITE, BLACK);
		return ' ';
		break;
	}
	case 1:
	{	
		CUtility::SetTextColor(CYAN, RED);
		cout << "#";
		break;
	}
	case 2:
		CUtility::SetTextColor(LIGHTGRAY, DARKGRAY);
		cout << "S";
		break;
	case 9:
		CUtility::SetTextColor(LIGHTGREEN, LIGHTCYAN);
		cout << "E";
		break;
	default:
		break;
	}
	CUtility::SetTextColor(WHITE, BLACK);
	return ' ';
}

Vector CMap::FindPlayerPosition()
{
	for (int y = 0; y < 10; ++y)
	{
		for (int x = 0; x < 10; ++x)
		{
			if (Data[y][x] == 2)
			{
				Vector Result;
				Result.x = x;
				Result.y = y;
				return Result;
			}
		}
	}
	return Vector();
}

Vector CMap::FindMonsterPosition()
{
	srand(unsigned(time(NULL)));

	int randomX = rand() % 10 + 1;
	int randomY = rand() % 10 + 1;

	while (true)
	{
		if (Data[randomX][randomY] == 0)
		{
			Vector Result;
			Result.x = randomX;
			Result.y = randomY;
			return Result;
		}
	}
	return Vector();
}


