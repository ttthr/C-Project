#include "CPlayer.h"



CPlayer::CPlayer()
{
	Position.x = 1;
	Position.y = 1;
}


CPlayer::~CPlayer()
{

}

void CPlayer::Move()
{
	cout << "플레이어 움직인다" << endl;
}

void CPlayer::Tick()
{
	Move();
}

void CPlayer::Render()
{
	cout << "@";
}
