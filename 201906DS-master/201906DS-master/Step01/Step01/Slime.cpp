#include "Slime.h"
#include <stdio.h>


Slime::Slime()
{
	printf("Slime 생성\n");

}


Slime::~Slime()
{
	printf("Slime 소멸\n");
}

void Slime::Move()
{
	printf("Slime 이동한다.\n");
}
