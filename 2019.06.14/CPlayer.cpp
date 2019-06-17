#include "CPlayer.h"
#include "CMap.h"


CPlayer::CPlayer()
{
	/*Position.x = 1;
	Position.y = 1;*/
}

CPlayer::CPlayer(CMap* const Newmap)
{
	map = Newmap;
	Position = map->FindPlayerPosition();
}


CPlayer::~CPlayer()
{

}

void CPlayer::Move()
{
	cout << "플레이어 움직인다" << endl;

	Vector NewPosition = Position;

	switch (CEngine::CurrentKeyInput)
	{
	case right:
	{
		NewPosition.x++;
		break;
	}
	case left:
	{
		NewPosition.x--;
		break;
	}
	case up:
	{
		NewPosition.y--;
		break;
	}
	case down:
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

	//Position.x = CUtility::clamp(Position.x, 1, 8);
	//Position.y = CUtility::clamp(Position.y, 1, 8);


	CEngine::CurrentKeyInput = 0;
}

void CPlayer::Tick()
{
	Move();
}

void CPlayer::Render()
{
	CUtility::SetXY(Position.x, Position.y);
	CUtility::SetTextColor(LIGHTGRAY, DARKGRAY);
	CUtility::SetObject('@');
	CUtility::SetTextColor(WHITE, BLACK); //렌더후 다시 색돌리기

}
