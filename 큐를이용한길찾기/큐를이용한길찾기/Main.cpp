#include<iostream>
using namespace std;
#include<queue>
#define MAX 10
#define WAY 0
#define WALL 1
#define BLOCK 2
#define PATH 3


class vector2
{
public:
	vector2(): x(100), y(0) { }

	~vector2(){}
public:
	int x;
	int y;
public:
	vector2 operator+(const vector2& RightHandSide)
	{
		vector2 Result;
		Result.x = this->x + RightHandSide.x;
		Result.y = this->y + RightHandSide.y;

		return Result;
	}
	vector2 operator+(const int& rhs)
	{
		vector2 Result;
		Result.x = this->x + rhs;

		return Result;
	}
};
vector2 Dir[4];

enum class Direction
{
	right = 0,
	down = 1,
	left = 2,
	up = 3
};

int maze[MAX][MAX] =
{
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 1, 1},
	{1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
	{1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
	{1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
	{1, 1, 0, 0, 0, 1, 1, 0, 1, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
};

bool CanMove(vector2& Current)
{

	for (int dir = (int)Direction::right; dir <= (int)Direction::up; ++dir)
	{	
		Current = Current + 1;

		if (Current.x < MAX - 1 && Current.y < MAX - 1)
		{
			cout << "탈출" << endl;
			break;
		}
	}

	return false; //다음 갈곳이 없음
}

void RenderMap()
{
	for (int y = 0; y < MAX; ++y)
	{
		for (int x = 0; x < MAX; ++x)
		{
			cout << maze[y][x] << " ";
		}
		cout << endl;
	}
}



int main()
{

	//방향 정보 매핑 초기화
	Dir[static_cast<int>(Direction::right)].x = 1;
	Dir[(int)Direction::right].y = 0;
	
	Dir[(int)Direction::down].x = 0;
	Dir[(int)Direction::down].y = 1;

	Dir[(int)Direction::left].x = -1;
	Dir[(int)Direction::left].y = 0;

	Dir[(int)Direction::up].x = 0;
	Dir[(int)Direction::up].y = -1;

	vector2 pos;
	queue<vector2> my_queue;
	my_queue.push(pos);
	cout << "(" << my_queue.front().x << "," << my_queue.front().y << ")" << endl;

	//큐가 비어있지않으면 
	if(!my_queue.empty())
	{
		while (true)
		{
			if (CanMove(pos))
			{
				my_queue.push(pos);
			}

		}
	}
	RenderMap();


	return 0;

}

//1.큐만들기
//처음 현재 위치에 (숫자를 적음, 100)
//초기화 할때 탈출구 못찾음
//탐색(큐가 비어있지 않으면)
/*{
	큐에서 정보꺼내기(현재위치)
	레벨(위치) 가져오기
	4방향이동(반복문)
	{
	   이동가능()
	   {
			다음위치(=)에 현재 위치 + 1 써주기
			다음위치(=)가 목적지인가?
			{
				-> 그럼 탈출
			}
			//아니면 다음위치 기록
			{
				큐에다가 기록
			}
	   }
	}
}*/

