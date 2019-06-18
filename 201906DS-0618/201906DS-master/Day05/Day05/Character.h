#pragma once
#include "Vector.h"

class Character
{
public:
	Character();
	virtual ~Character();

	class Vector Position;

	virtual void Tick() = 0;
	virtual void Render() = 0;

protected:
	virtual void Move() = 0;
};

