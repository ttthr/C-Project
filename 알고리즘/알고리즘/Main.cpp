#include<iostream>
using namespace std;
#include<queue>
#include<stack>
#define MAX 5
#define WAY 0
#define WALL 1
#define BLOCK 2
#define PATH 3
#define Level 100

class Position
{
public:
	Position() : x(0), y(0) { }
	Position(int _x ,int _y) : x(_x), y(_y){}
	~Position() {}
public:
	int x;
	int y;
public:
	Position operator+(const Position& RightHandSide)
	{
		Position Result;
		Result.x = this->x + RightHandSide.x;
		Result.y = this->y + RightHandSide.y;

		return Result;
	}
	Position operator+(const int& rhs)
	{
		Position Result;
		Result.x = this->x + rhs;

		return Result;
	}
};

Position Dir[4];

enum class Direction
{
	right = 0,
	down = 1,
	left = 2,
	up = 3
};

int Maze[MAX][MAX] =
{
	{0,1,1,1,0},
	{0,0,0,0,0},
	{1,0,1,1,1},
	{1,0,1,1,1},
	{1,0,0,0,0}
	
};
int MaxLevel = 0;
int main()
{
	Dir[static_cast<int>(Direction::right)].x = 1;
	Dir[(int)Direction::right].y = 0;

	Dir[(int)Direction::down].x = 0;
	Dir[(int)Direction::down].y = 1;

	Dir[(int)Direction::left].x = -1;
	Dir[(int)Direction::left].y = 0;

	Dir[(int)Direction::up].x = 0;
	Dir[(int)Direction::up].y = -1;

	// ¸Ê ·»´õ
	for (int y = 0; y < MAX; ++y)
	{
		for (int x = 0; x < MAX; ++x)
		{
			cout << Maze[y][x] << " ";
		}
		cout << endl;
	}
	queue<Position> my_queue;
	stack<Position> my_Stack;
	Position CurrentPos;
	Position TempPos;
	Position ResultPos;
	my_queue.push(CurrentPos);
	Maze[CurrentPos.y][CurrentPos.x] = Level;

	while (!my_queue.empty())
	{
		CurrentPos = my_queue.front();
		my_queue.pop();

		int myLevel = Maze[CurrentPos.y][CurrentPos.x];

		for (int dir = (int)Direction::right; dir <= (int)Direction::up; ++dir)
		{
			
			TempPos = CurrentPos + Dir[dir];
			
			if (TempPos.x < 0 || TempPos.y < 0 || TempPos.x > MAX - 1 || TempPos.y > MAX - 1)
			{
				break;
			} 
			if (Maze[TempPos.y][TempPos.x] == WAY)
			{		

				Maze[TempPos.y][TempPos.x] = myLevel + 1;
				my_queue.push(TempPos);
				my_Stack.push(CurrentPos);
				if (!my_Stack.empty())
				{
					cout << "(" << my_Stack.top().x << "," << my_Stack.top().y << ")";
			
				}
						
				//cout << "(" << my_queue.front().x << "," << my_queue.front().y << ")";
			}

			if (TempPos.x == MAX - 1 && TempPos.y == MAX - 1)
			{
				MaxLevel = Maze[TempPos.y][TempPos.x];
				cout << "Å»Ãâ" << endl;
				break;
			}
		
		}

	}
	cout << endl;

	for (int y = 0; y < MAX; ++y)
	{
		for (int x = 0; x < MAX; ++x)
		{
			cout << Maze[y][x] << " ";
		}

		cout << endl;
	}




	return 0;
}