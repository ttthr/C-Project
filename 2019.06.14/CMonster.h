#pragma once
#include "Define.h"
#include "CCharacter.h"
class CMonster :
	public CCharacter
{
public:
	CMonster();
	virtual ~CMonster();
protected:	
	virtual void Move()override;
public:
	virtual void Tick() override;
	virtual void Render() override;
};

