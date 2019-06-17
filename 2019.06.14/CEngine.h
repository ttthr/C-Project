#pragma once
#include "Define.h"
#include "CCharacter.h"
#include "CMap.h"
#include "CPlayer.h"
#include "CMonster.h"

class CEngine
{
public:
	CEngine();
	virtual~CEngine();
public:
	virtual bool Init();
	virtual bool Run();
	virtual bool Term();
protected:
	bool bIsRunning;
	virtual void input();
	virtual void Tick();
	virtual void Render();
	virtual bool GameLoop();
protected:
	int CurrentKeyInput;
	vector<CCharacter*> m_Characters;
	CMap* m_map;
public:
	void KeyInput(int _CurrentKeyInput);
	void Collision();

};

