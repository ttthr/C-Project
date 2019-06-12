#include "CPlayer.h"



CPlayer::CPlayer()
{
	std::cout << "플레이어 생성자." << std::endl;
}


CPlayer::~CPlayer()
{
	std::cout << "플레이어 소멸자." << std::endl;
}

void CPlayer::Move()
{
	std::cout << "플레이어 이동한다." << std::endl;
}
