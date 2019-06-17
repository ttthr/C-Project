#include "CMonster.h"
#include "CMap.h"


CMonster::CMonster()
{
	//몬스터 초기화
	Position.x = 2;
	Position.y = 2;

}

CMonster::CMonster(CMap * const Newmap)
{
	map = Newmap;
	Position = map->FindMonsterPosition();
}


CMonster::~CMonster()
{

}

void CMonster::Move()
{
	srand(unsigned(time(NULL)));

	int Dir = rand() % 4 + 1;

	Vector NewPosition = Position;

	switch (Dir)
	{
	case 1:
	{
		NewPosition.x++;
		break;
	}
	case 2:
	{
		NewPosition.x--;
		break;
	}
	case 3:
	{
		NewPosition.y--;
		break;
	}
	case 4:
	{
		NewPosition.y++;
		break;
	}
	}

	if (map->Data[NewPosition.y][NewPosition.x] == 1)
	{
		// 이동 불가
	}
	else
	{
		//이동 가능
		Position = NewPosition;
	}
	//srand(unsigned(time(NULL)));

	//int randomX = rand() % 10 + 1;
	//int randomY = rand() % 10 + 1;

	//Position.x = randomX;
	//Position.y = randomY;

	//cout << "몬스터 움직임" << endl;
	//cout << "몬스터좌표 x : " << Position.x << "몬스터 좌표 y : " << Position.y << endl;
}

void CMonster::Tick()
{
	Move();
}

void CMonster::Render()
{
	CUtility::SetXY(Position.x, Position.y);
	CUtility::SetTextColor(LIGHTGRAY, DARKGRAY);
	CUtility::SetObject('#');
	CUtility::SetTextColor(WHITE, BLACK); //렌더후 다시 색돌리기

}
