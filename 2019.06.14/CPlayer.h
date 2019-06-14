#pragma once
#include "CCharacter.h"
class CPlayer :
	public CCharacter
{
public:
	CPlayer();
	virtual ~CPlayer();
public:
	virtual void Move() override;
};

