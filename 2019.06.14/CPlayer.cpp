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
	cout << "�÷��̾� �����δ�" << endl;
}

void CPlayer::Tick()
{
	Move();
}

void CPlayer::Render()
{
	cout << "@";
}
