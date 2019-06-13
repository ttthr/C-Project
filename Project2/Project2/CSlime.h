#pragma once
#include "CMonster.h"
class CSlime :
	public CMonster
{
public:
	CSlime();
	virtual ~CSlime();
public:
	virtual void Move();
	virtual void Draw();


};

