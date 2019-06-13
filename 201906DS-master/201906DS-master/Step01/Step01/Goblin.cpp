#include "Goblin.h"
#include <stdio.h>


Goblin::Goblin()
{
	printf("고블린 생성\n");
}


Goblin::~Goblin()
{
	printf("고블린 소멸\n");
}

void Goblin::Move()
{
	printf("Goblin 이동한다.\n");
}
