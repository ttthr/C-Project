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

//2019.06.13 ( �� ����)
//Ŭ���� ���� ����
// Character �����( Player, Monster ���� �� )
// Player -> Character���
// Monster -> Character ���
// Gobin - > Monster ���
// Silme - > Monster ���
// Wildpig - > Monster ���

// Engine ( Init , Run , Tick , Render )
// Character Move() �Լ� ����
// Engine�� ����� Player�� ������.
// Engine Run()���� Input(), Tick(), Render() ȣ��
// Engine Init() �÷��̾� �Ҵ�,�ʱ�ȭ
// Engine ������ �ܿ��� �ʱ�ȭ �ϱ�
// Engine new�� �����Ѱ� �����Լ�( Term() ) ����� �ֱ� 
// �̰��� �Ҹ��ڿ��� �θ� ( �� �Ҹ��ڴܿ��� �ص��� )
// Engine�� ���� 3���� �Ҵ�, �ʱ�ȭ
// �÷��̾�,���� class�� Move()�Լ� �����(������)
// ���� �������� ����� ( �迭�� ���� , ������ ����� )
// Engine Move()�Լ� �ٲٱ�
// Engine Init()���� �������� �Ҵ�޵��� �ϱ� ( rand() ��� , srand(), stdlib.h �߰� )
// 




//*** Tip ***//
//������ ������� delete ���ִ� �������̱�



int main()
{

	CEngine* pEngine = new CEngine; //���� �ȿ��� �� ����
	CMap* pMap = new CMap;  // �� �ȿ��� �÷��̾�,���� ����
	CMonster* pMonster = new CWildpig;
	CPlayer* pPlayer = new CPlayer;

	pEngine->Init(pPlayer, pMonster, pMap);
	pEngine->Run();

	if (pEngine != NULL)
	{
		delete pEngine;
		pEngine = NULL;
	}

}