#include "CMonster.h"



CMonster::CMonster()
{
	//���� �ʱ�ȭ
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

	cout << "���� ������" << endl;
	cout << "������ǥ x : " << Position.x << "���� ��ǥ y : " << Position.y << endl;
}

void CMonster::Tick()
{
	Move();
}

void CMonster::Render()
{
	cout << "#";

}
