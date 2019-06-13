#pragma once
#include "CMonster.h"
class CWildpig :
	public CMonster
{
public:
	CWildpig();
	virtual ~CWildpig();
public:
	virtual void Move();
	virtual void Draw();

};

