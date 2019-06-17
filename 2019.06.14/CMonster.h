#pragma once
#include "Define.h"
#include "CCharacter.h"
class CMap;

class CMonster :
	public CCharacter
{
public:
	CMonster();
	CMonster(CMap* const Newmap);
	virtual ~CMonster();
public:
	CMap* map;
protected:	
	virtual void Move()override;
public:
	virtual void Tick() override;
	virtual void Render() override;
};

