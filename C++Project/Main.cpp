#include<iostream>
#include"Engine.h"
#include"CPlayer.h"
#include "CMap.h"
#include "CUtility.h"
using namespace std;

//#define LEFT  75
//#define RIGHT 77
//#define UP    72 
//#define DOWN  80 

//2019.06.10 
// " " : 내폴더에서도 찾아봐라
// < > : 컴파일러가 지정한 곳에서만 찾아봐라
// Basic : 배열 인덱스가 1부터 시작함

//2019.06.11
//void : 형태가 정해져 있지 않다.
// stack
// 프로그램카운터(PC)


//2019.06.12
//객체지향 프로그래밍


int main()
{
	CEngine* Engine = new CEngine;
	CPlayer* pPlayer = new CPlayer;
	CMap* pMap = new CMap;

	Engine->Init(pPlayer, pMap);			
	Engine->Run();

	delete Engine;

	return 0;

}