#include "CMonster.h"
#include "CUtility.h"


CMonster::CMonster()
{
	//std::cout << "���� ������." << std::endl;
}


CMonster::~CMonster()
{
	//std::cout << "���� �Ҹ���." << std::endl;
}

void CMonster::Move()
{
	//std::cout << "���Ͱ� �̵��Ѵ�." << std::endl;
	m_x = CUtility::clamp(m_x, 1, 8);
	m_y = CUtility::clamp(m_y, 1, 8);
}

void CMonster::Tick(int _KeyInput)
{
	Move();
}

void CMonster::Draw()
{
	//std::cout << "9";
}
