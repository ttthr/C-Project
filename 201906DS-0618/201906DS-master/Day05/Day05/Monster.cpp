#include "Monster.h"
#include "Util.h"
#include "Engine.h"



Monster::Monster()
{
}

Monster::Monster(Map * const newMap)
{
	mapData = newMap;
	Position = mapData->FindMonsterPosition();
}


Monster::~Monster()
{
}

void Monster::Tick()
{
	Move();
}

void Monster::Render()
{
	Util::SetXY(Position.X, Position.Y);
	Util::TextColor(GREEN, BLACK);
	Util::SetObject('&');
}

void Monster::Move()
{
	//srand((unsigned int)time(0));
	int dir = rand() % 4 + 1;
	Vector NewPosition = Position;

	switch (dir)
	{
	case 1:
		NewPosition.X++;
		break;
	case 2:
		NewPosition.X--;
		break;
	case 3:
		NewPosition.Y--;
		break;
	case 4:
		NewPosition.Y++;
		break;
	}

	//이동 미리 예측
	if (mapData->Data[NewPosition.Y][NewPosition.X] == 1)
	{
		//이동불가
	}
	else
	{
		//이동 가능
		Position = NewPosition;
	}

	//	Position.X = Util::Clamp(Position.X, 1, 8);
	//	Position.Y = Util::Clamp(Position.Y, 1, 8);
}
