#pragma once
#include "Define.h"
#include "CCharacter.h"
#include "CEngine.h"

class CMap;

class CPlayer :
	public CCharacter
{
public:
	CPlayer();
	CPlayer(CMap* const Newmap);
	virtual ~CPlayer();
protected:
	virtual void Move() override;
	CMap* map;
public:
	virtual void Tick() override;
	virtual void Render() override;
};

