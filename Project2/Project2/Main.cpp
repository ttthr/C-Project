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

int main()
{

	CEngine* pEngine = new CEngine;
	CPlayer* pPlayer = new CPlayer;
	CMap* pMap = new CMap;
	pEngine->Init(pPlayer, pMap); //몬스터 추가해줘야함
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