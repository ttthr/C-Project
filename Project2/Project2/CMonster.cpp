#include "CMonster.h"
#include "CUtility.h"


CMonster::CMonster()
{
	//std::cout << "몬스터 생성자." << std::endl;
}


CMonster::~CMonster()
{
	//std::cout << "몬스터 소멸자." << std::endl;
}

void CMonster::Move()
{
	m_x = CUtility::clamp(m_x, 1, 8);
	m_y = CUtility::clamp(m_y, 1, 8);
}

void CMonster::Tick(int _KeyInput)
{
	Move();
}

void CMonster::Render()
{

}
