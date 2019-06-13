#pragma once
#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin();
	virtual ~Goblin();

	virtual void Move() override;
};

