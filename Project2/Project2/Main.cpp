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
//Ŭ���� ���� ����
// Character �����( Player, Monster ���� �� )
// Player -> Character���
// Monster -> Character ���
// Gobin - > Monster ���
// Silme - > Monster ���
// Wildpig - > Monster ���

// Engine ( Init , Run , Tick , Render )
// Character Move() �Լ� ����


int main()
{

	CEngine* pEngine = new CEngine; //���� �ȿ��� �� ����
	CPlayer* pPlayer = new CPlayer;
	CMap* pMap = new CMap;  // �� �ȿ��� �÷��̾�,���� ����
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