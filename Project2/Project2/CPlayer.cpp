#include "CPlayer.h"
#include "CUtility.h"


CPlayer::CPlayer()
{
	//std::cout << "플레이어 생성자." << std::endl;

}


CPlayer::~CPlayer()
{
	//std::cout << "플레이어 소멸자." << std::endl;
}

void CPlayer::Move(int _KeyInput)
{
	switch (_KeyInput)
	{
	case CPlayer::right:
	{
		x++;
		break;
	}
	case CPlayer::left:
	{
		x--;
		break;
	}
	case CPlayer::up:
	{
		y--;
		break;
	}
	case CPlayer::down:
	{
		y++;
		break;
	}

	default:
		break;
	}

	x = CUtility::clamp(x, 1, 8);
	y = CUtility::clamp(y, 1, 8);
}

void CPlayer::Tick(int _KeyInput)
{
	Move(_KeyInput);
}

void CPlayer::Render()
{
	std::cout << "@";
}
