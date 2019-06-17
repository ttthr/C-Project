#include "CMonster.h"



CMonster::CMonster()
{
	//몬스터 초기화
	Position.x = 7;
	Position.y = 7;
}


CMonster::~CMonster()
{

}

void CMonster::Move()
{
	srand(unsigned(time(NULL)));

	int randomX = rand() % 10 + 1;
	int randomY = rand() % 10 + 1;

	Position.x = randomX;
	Position.y = randomY;

	cout << "몬스터 움직임" << endl;
	cout << "몬스터좌표 x : " << Position.x << "몬스터 좌표 y : " << Position.y << endl;
}

void CMonster::Tick()
{
	Move();
}

void CMonster::Render()
{
	cout << "#";

}
