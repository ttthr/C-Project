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
// " " : ������������ ã�ƺ���
// < > : �����Ϸ��� ������ �������� ã�ƺ���
// Basic : �迭 �ε����� 1���� ������

//2019.06.11
//void : ���°� ������ ���� �ʴ�.
// stack
// ���α׷�ī����(PC)


//2019.06.12
//��ü���� ���α׷���


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