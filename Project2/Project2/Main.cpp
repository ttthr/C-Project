#include<iostream>
using namespace std;

#include "CPlayer.h"
#include "CMonster.h"
#include "CSlime.h"
#include "CWildpig.h"
#include "CGoblin.h"
#include "CMap.h"
#include "Engine.h"
#include "CUtility.h"

//2019.06.13
//클래스 설계 구조
// Character 만들기( Player, Monster 공통 값 )
// Player -> Character상속
// Monster -> Character 상속
// Gobin - > Monster 상속
// Silme - > Monster 상속
// Wildpig - > Monster 상속

// Engine ( Init , Run , Tick , Render )
// Character Move() 함수 구현


int main()
{

	CEngine* pEngine = new CEngine; //엔진 안에서 맵 해제
	CPlayer* pPlayer = new CPlayer;
	CMap* pMap = new CMap;  // 맵 안에서 플레이어,몬스터 해제
	CMonster* pMonster = new CWildpig;

	pEngine->Init(pPlayer, pMonster, pMap); 
	pEngine->Run();

	delete pEngine;

	/*CMap* pMap = new CMap;
	pMap->Draw();

	CPlayer* pPlayer = new CPlayer;
	pPlayer->Move();

	CMonster* pWildpig = new CWildpig;
	pWildpig->Move();

	CMonster* pSlime = new CSlime;
	pSlime->Move();

	CMonster* pGoblin = new CGoblin;
	pGoblin->Move();

	delete pWildpig;
	delete pSlime;
	delete pGoblin;
	delete pPlayer;
	delete pMap;*/

}