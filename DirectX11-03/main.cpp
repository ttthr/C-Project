#include<iostream>
using namespace std;
#include "Engine.h"

//2910.07.02 4시 35분 Draw 시작

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR  pCmdLine, int nCmdShow)
{	

	Engine myEngine(hInstance);

	if (myEngine.Init() == false)
	{
		return 0;
	}

	return myEngine.Run();
}