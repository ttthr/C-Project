#include "CMonster.h"



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
	std::cout << "몬스터가 이동한다." << std::endl;
}
