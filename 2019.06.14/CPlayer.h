#pragma once
#include "Define.h"
#include "CCharacter.h"
class CPlayer :
	public CCharacter
{
public:
	CPlayer();
	virtual ~CPlayer();
protected:
	virtual void Move() override;
public:
	virtual void Tick() override;
	virtual void Render() override;
};

