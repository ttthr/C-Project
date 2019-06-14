#pragma once
#include "Vector.h"

class CCharacter
{
public:
	CCharacter();
	virtual ~CCharacter();
protected:
	virtual void  Move() = 0;
public:
	virtual void Tick() = 0;
	virtual void Render() = 0;
public:
	Vector Position;
};

