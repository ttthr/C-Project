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
	std::cout << "�������� �̵��Ѵ�." << std::endl;
}

void CSlime::Draw()
{
	std::cout << "&";
}
