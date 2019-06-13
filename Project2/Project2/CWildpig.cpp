#include "CWildpig.h"

CWildpig::CWildpig()
{
	m_x = 3;
	m_y = 4;
}

CWildpig::~CWildpig()
{

}

void CWildpig::Move()
{
	std::cout << "¸äµÅÁö°¡ ÀÌµ¿ÇÑ´Ù." << std::endl;
}
void CWildpig::Draw()
{
	std::cout << "#";
}
