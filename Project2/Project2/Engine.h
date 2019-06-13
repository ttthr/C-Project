#pragma once
#include<conio.h>
#include<iostream>

using namespace std;
class CPlayer;
class CMap;
class CUtility;

//#define LEFT  75
//#define RIGHT 77
//#define UP    72 
//#define DOWN  80 

class CEngine
{
public:
	CEngine();
	~CEngine();
public:
	//CPlayer* m_pPlayer;
	CMap* m_map;
	//CUtility* m_Utility;
public:
	void Init(CPlayer* _pPlayer , CMap* _pMap);
	void Run();
	void Draw();
	void Tick(int _KeyInput); //Update의미( 언리얼에선 Tick이라고 부름)
	int Input();

	bool bIsRunning = true;
};
