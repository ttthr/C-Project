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
	std::cout << "����� �̵��Ѵ�." << std::endl;
}
void CGoblin::Draw()
{
	std::cout << "=";
}
