#include "CPlayer.h"
#include "CUtility.h"


CPlayer::CPlayer()
	:x(1), y(1)
{

}

CPlayer::~CPlayer()
{

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

void CPlayer::Draw()
{
	std::cout << "@";
}
