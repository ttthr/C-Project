#include <stdio.h>
#include "Engine.h"
#include "MyEngine.h"

int main()
{
	Engine* engine = new MyEngine();

	engine->Run();

	delete engine;
	engine = nullptr;

	return 0;
}
//
//C++
//Hello World
//빌드 환경 설정
//간단한 프로그램 이 프로그램 구조
//
//상수
//자료형
//연산자
//변수
//배열
//반복문
//조건문
//포인터
//함수
//클래스
//클래스 설계 방법
//데이터모델링
//게임 만들기
//상속
//다형성(오버라이딩, virtual, override)
//클래스 관계(is a, has a)
//const, overload
//게임 엔진 구조
//While(1)
//{
//	Input()
//		Tick()
//		Redner()
//}
//
//
//
//
