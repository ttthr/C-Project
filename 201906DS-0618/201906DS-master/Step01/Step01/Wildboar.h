#pragma once
#include "Monster.h"

class Wildboar : public Monster
{
public:
	Wildboar();
	virtual ~Wildboar();

	virtual void Move() override;
};

