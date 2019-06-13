#include "CGoblin.h"



CGoblin::CGoblin()
{
	m_x = 1;
	m_y = 1;
}


CGoblin::~CGoblin()
{
}

void CGoblin::Move()
{
	std::cout << "고블린이 이동한다." << std::endl;
}
void CGoblin::Draw()
{
	std::cout << "=";
}
