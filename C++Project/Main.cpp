#include<iostream>
#include"Engine.h"
#include"CPlayer.h"
#include "CMap.h"
#include "CUtility.h"

//2019.06.10 
// " " : ������������ ã�ƺ���
// < > : �����Ϸ��� ������ �������� ã�ƺ���
// Basic : �迭 �ε����� 1���� ������
using namespace std;

#define LEFT  75
#define RIGHT 77
#define UP    72 
#define DOWN  80 

//void : ���°� ������ ���� �ʴ�.
// stack
// ���α׷�ī����(PC)


int main()
{
	CEngine* Engine = new CEngine;
	//Engine->Run();

	delete Engine;

	return 0;

}