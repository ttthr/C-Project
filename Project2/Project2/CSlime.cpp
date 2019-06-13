#include "CSlime.h"



CSlime::CSlime()
{
	m_x = 2;
	m_y = 3;
}

CSlime::~CSlime()
{


}

void CSlime::Move()
{
	std::cout << "슬라임이 이동한다." << std::endl;
}

void CSlime::Draw()
{
	std::cout << "&";
}
