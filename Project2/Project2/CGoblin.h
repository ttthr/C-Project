#pragma once
#include "CMonster.h"
class CGoblin :
	public CMonster
{
public:
	CGoblin();
	virtual ~CGoblin();
public:
	virtual void Move();
	virtual void Draw();

};

