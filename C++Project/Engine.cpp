#include "Engine.h"

CEngine::CEngine()
{
}

CEngine::~CEngine()
{
}

void CEngine::Run()
{
	while (bIsRunning)
	{
		int keyInput = Input();
		Tick(keyInput);
		Draw();

	}

}

void CEngine::Draw()
{
	//system("cls");

	//for (int i = 0; i < 10; ++i)
	//{
	//	for (int j = 0; j < 10; ++j)
	//	{
	//		if (i == playerx && j == playery)
	//			cout << "@";
	//		else
	//			cout << map[i][j];

	//	}
	//	cout << endl;
	//}

}

void CEngine::Tick(int KeyInput)
{
	//switch (_KeyInput)
	//{
	//case RIGHT:
	//{
	//	PlayerX++;
	//	break;
	//}
	//case LEFT:
	//{
	//	PlayerX--;
	//	break;
	//}
	//case UP:
	//{
	//	PlayerY--;
	//	break;
	//}
	//case DOWN:
	//{
	//	PlayerY++;
	//	break;
	//}
	//case 5:
	//	bIsRunning = false;
	//	break;

	//default:
	//	break;
	//}

	//PlayerX = clamp(PlayerX, 1, 8);
	//PlayerY = clamp(PlayerY, 1, 8);

}

int CEngine::Input()
{

	int KeyInput = getch();

	return KeyInput;
}
