#include<iostream>
using namespace std;
#include<stack>
#include<list>
#define MAX 10
#define WAY 0
#define WALL 1
#define BLOCK 2
#define PATH 3

stack<int> stackX;
stack<int> stackY;
stack<int> stackStorageX;
stack<int> stackStorageY;

int maze[MAX][MAX]
{
	{0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
	{1, 1, 1, 0, 1, 1, 0, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
	{1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
};
void PrintMap()
{
	for (int y= 0; y < MAX; ++y)
	{
		for (int x = 0; x < MAX; ++x)
		{
			cout << maze[y][x];
		}
		cout << endl;
	}
}
//bool FindMaze(int x, int y)
//{
//	if (x < 0 || y < 0 || x > MAX - 1 || y > MAX - 1) //범위 체크
//	{
//		return false;
//	}
//	else if (maze[y][x] != WAY) //길이 아니면
//	{
//		return false;
//	}
//	목적지 이면
//	else if (x == MAX - 1 && y == MAX - 1)
//	{
//		지도에 표시
//		maze[y][x] = PATH;
//		return true;
//	}
//	이동
//	else
//	{
//		maze[y][x] = PATH;
//
//		if (FindMaze(x + 1, y))
//		{
//			cout << "(" << x << "," << y << ")" << endl;
//			return true;
//		}
//		else if (FindMaze(x, y + 1))
//		{
//			cout << "(" << x << "," << y << ")" << endl;
//			return true;
//		}
//		else if (FindMaze(x - 1, y))
//		{
//			cout << "(" << x << "," << y << ")" << endl;
//			return true;
//		}
//		else if (FindMaze(x, y - 1))
//		{
//			cout << "(" << x << "," << y << ")" << endl;
//			return true;
//		}
//		else
//		{
//			maze[y][x] = BLOCK;
//			return false;
//		}
//	}
//	return true;
//
//}
bool FindMaze(int x , int y)
{	
	stackX.push(x);
	stackY.push(y);


		while (true)
		{
			if (maze[y][x] == WAY)
			{
				stackX.top() = x++;
				//cout << "(" << stackX.top() << "," << stackY.top() << ")"<<" " ;

			}
			else if (maze[y][x] == WALL)
			{
				x = x - 1;
				x = stackX.top();
				//cout << "(" << stackX.top() << "," << stackY.top() << ")" << " ";
				break;
			}
			cout << "(" << stackX.top() << "," << stackY.top() << ")" << " ";
		}
		while (true)
		{
			if (maze[y][x] == WAY)
			{
				stackY.top() = y++;
				//cout << "(" << stackX.top() << "," << stackY.top() << ")" << " ";

			}
			else if (maze[y][x] == WALL)
			{
				y = y - 1;
				y = stackY.top();
				break;
			}
			cout << "(" << stackX.top() << "," << stackY.top() << ")" << " ";
		}
		while (true)
		{
			if (maze[y][x] == WAY)
			{
				stackX.top() = x--;
				//cout << "(" << stackX.top() << "," << stackY.top() << ")" << " ";
				cout << endl;
			}
			else if (maze[y][x] == WALL)
			{
				x = x - 1;
				x = stackX.top();
				break;
			}
			cout << "(" << stackX.top() << "," << stackY.top() << ")" << " ";
		}
		while (true)
		{
			if (maze[y][x] == WAY)
			{
				stackY.top() = y--;
				//cout << "(" << stackX.top() << "," << stackY.top() << ")" << " ";
				cout << endl;
			}
			else if (maze[y][x] == WALL)
			{
				y = y - 1;
				y = stackY.top();
				break;
			}
			cout << "(" << stackX.top() << "," << stackY.top() << ")" << " ";

			if (x == stackX.top() && y == stackY.top())
			{
				cout << "종료" << endl;
				system("pause");
				break;
			}

		}

	return true;
}


int main()
{

	PrintMap();
	FindMaze(0, 0);

	return 0;
}


//if (x < 0 || y < 0 || x > MAX - 1 || y > MAX - 1) //범위 체크
	//{
	//	return false;
	//}
	//else if (maze[y][x] != WAY) //길이 아니면
	//{
	//	return false;
	//}
	////목적지 이면
	//else if (x == MAX - 1 && y == MAX - 1)
	//{
	//	//지도에 표시
	//	maze[y][x] = PATH;
	//	return true;
	//}
	////이동
	//else
	//{
	//	maze[y][x] = PATH;

	//	if (FindMaze(x + 1, y))
	//	{
	//		//cout << "(" << x << "," << y << ")" << endl;
	//		return true;
	//	}
	//	else if (FindMaze(x, y + 1))
	//	{
	//		//cout << "(" << x << "," << y << ")" << endl;
	//		return true;
	//	}
	//	else if (FindMaze(x - 1, y))
	//	{
	//		//cout << "(" << x << "," << y << ")" << endl;
	//		return true;
	//	}
	//	else if (FindMaze(x, y - 1))
	//	{
	//		//cout << "(" << x << "," << y << ")" << endl;
	//		return true;
	//	}
	//	else
	//	{
	//		maze[y][x] = BLOCK;
	//		return false;
	//	}
	//}
	//return true;