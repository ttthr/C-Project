#pragma once
#include "Define.h"
#include "CEngine.h"
class CPlayer;
class CMonster;
class CMap;

class CMyEngine :
	public CEngine
{
public:
	CMyEngine();
	virtual ~CMyEngine();
public:
	virtual bool Init()override;
	virtual bool Run()override;
	virtual bool Term()override;

protected:
	virtual void input()override;
	virtual void Tick()override;
	virtual void Render()override;
};

