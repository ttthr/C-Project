#include<iostream>
using namespace std;
#include "Engine.h"
#include "App.h"


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR  pCmdLine, int nCmdShow)
{

	Engine myEngine(hInstance);

	if (myEngine.Init() == false)
	{
		return 0;
	}

	return myEngine.Run();
}
//int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
//{
//
//
//	Engine myEngine(hInstance);
//
//	if (myEngine.Init() == false)
//	{
//		return 0;
//	}
//
//	return myEngine.Run();
//	
//}
