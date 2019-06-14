#pragma once
#include "CCharacter.h"
class CMonster :
	public CCharacter
{
public:
	CMonster();
	virtual ~CMonster();
public:
	virtual void Move()override;
};

