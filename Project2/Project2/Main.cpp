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

//2019.06.13 ( 쌤 구조)
//클래스 설계 구조
// Character 만들기( Player, Monster 공통 값 )
// Player -> Character상속
// Monster -> Character 상속
// Gobin - > Monster 상속
// Silme - > Monster 상속
// Wildpig - > Monster 상속

// Engine ( Init , Run , Tick , Render )
// Character Move() 함수 구현
// Engine이 멤버로 Player를 가진다.
// Engine Run()에서 Input(), Tick(), Render() 호출
// Engine Init() 플레이어 할당,초기화
// Engine 생성자 단에서 초기화 하기
// Engine new로 생성한거 삭제함수( Term() ) 만들어 주기 
// 이것을 소멸자에서 부름 ( 걍 소멸자단에서 해도됨 )
// Engine이 몬스터 3종류 할당, 초기화
// 플레이어,몬스터 class에 Move()함수 만들기(재정의)
// 몬스터 여러마리 만들기 ( 배열로 생성 , 삭제도 만들기 )
// Engine Move()함수 바꾸기
// Engine Init()에서 랜덤으로 할당받도록 하기 ( rand() 사용 , srand(), stdlib.h 추가 )
// 




//*** Tip ***//
//생성한 순서대로 delete 해주는 버릇들이기



int main()
{

	CEngine* pEngine = new CEngine; //엔진 안에서 맵 해제
	CMap* pMap = new CMap;  // 맵 안에서 플레이어,몬스터 해제
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