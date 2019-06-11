#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

// " " : 내폴더에서도 찾아봐라
// < > : 컴파일러가 지정한 곳에서만 찾아봐라
// Basic : 배열 인덱스가 1부터 시작함


using namespace std;

#define LEFT  75
#define RIGHT 77
#define UP    72 
#define DOWN  80 


//void : 형태가 정해져 있지 않다.
// stack
// 프로그램카운터(PC)

int clamp(int Current, int Min, int Max)
{
	if (Current < Min)
	{
		return Min;
	}
	if (Current > Max)
	{
		return Max;
	}

	return Current;
}
//d

int map[10][10]{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,2},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1},

};
//dddd

int PlayerX = 1;
int PlayerY = 1;

int Input()
{
	int KeyInput = getch();

	return KeyInput;

}
void Tick(int _KeyInput)
{
	switch (_KeyInput)
	{
	case RIGHT:
	{
		PlayerX++;
		break;
	}
	case LEFT:
	{
		PlayerX--;
		break;
	}
	case UP:
	{
		PlayerY--;
		break;
	}
	case DOWN:
	{
		PlayerY++;
		break;
	}
	default:
		break;
	}

	PlayerX = clamp(PlayerX, 1, 8);
	PlayerY = clamp(PlayerY, 1, 8);

}

void Draw()
{
	system("cls");

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (i == PlayerX && j == PlayerY)
				cout << "@";
			else
				cout << map[i][j];

		}
		cout << endl;
	}


}



int main()
{

	while (1)
	{
		int keyInput = Input();
		Tick(keyInput);
		Draw();
		if (PlayerX == 1 && PlayerY == 9)
		{
			system("cls");
			cout << "탈출" << endl;
			break;
		}
	}

	return 0;

}