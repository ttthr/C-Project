#include "Player.h"
#include <stdio.h>


Player::Player()
{
	printf("Player 생성\n");
}


Player::~Player()
{
	printf("Player 소멸\n");
}

void Player::Move()
{
	printf("Player 이동한다.\n");
}
