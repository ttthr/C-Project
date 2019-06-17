#include "CMonster.h"
#include "CMap.h"


CMonster::CMonster()
{
	//���� �ʱ�ȭ
	Position.x = 2;
	Position.y = 2;

}

CMonster::CMonster(CMap * const Newmap)
{
	map = Newmap;
	Position = map->FindMonsterPosition();
}


CMonster::~CMonster()
{

}

void CMonster::Move()
{
	srand(unsigned(time(NULL)));

	int Dir = rand() % 4 + 1;

	Vector NewPosition = Position;

	switch (Dir)
	{
	case 1:
	{
		NewPosition.x++;
		break;
	}
	case 2:
	{
		NewPosition.x--;
		break;
	}
	case 3:
	{
		NewPosition.y--;
		break;
	}
	case 4:
	{
		NewPosition.y++;
		break;
	}
	}

	if (map->Data[NewPosition.y][NewPosition.x] == 1)
	{
		// �̵� �Ұ�
	}
	else
	{
		//�̵� ����
		Position = NewPosition;
	}
	//srand(unsigned(time(NULL)));

	//int randomX = rand() % 10 + 1;
	//int randomY = rand() % 10 + 1;

	//Position.x = randomX;
	//Position.y = randomY;

	//cout << "���� ������" << endl;
	//cout << "������ǥ x : " << Position.x << "���� ��ǥ y : " << Position.y << endl;
}

void CMonster::Tick()
{
	Move();
}

void CMonster::Render()
{
	CUtility::SetXY(Position.x, Position.y);
	CUtility::SetTextColor(LIGHTGRAY, DARKGRAY);
	CUtility::SetObject('#');
	CUtility::SetTextColor(WHITE, BLACK); //������ �ٽ� ��������

}
