#include <iostream>
#include <stack>

using namespace std;

#define MAX 10
#define WAY 0
#define WALL 1
#define BLOCK 2
#define PATH 3

class Vector2
{
public:
	Vector2() : x(0), y(0) {}
	int x;
	int y;

	Vector2 operator+(const Vector2& RightHandSide)
	{
		Vector2 Result;
		Result.x = this->x + RightHandSide.x;
		Result.y = this->y + RightHandSide.y;

		return Result;
	}
};

enum class Direction
{
	Right	= 0,
	Down	= 1,
	Left	= 2,
	Up		= 3
};

Vector2 Dir[4];


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
	{1, 1, 0, 0, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
};

//현재위치에서 일정한 방법으로 미리 이동 해보고 
//이동 가능한지 알려줌
bool CanMove(Vector2& Current) 
{
	Vector2 Next;

	//4방향 움직이기
	for(int dir = (int)Direction::Right; dir <= (int)Direction::Up; ++dir)
	{
		Next = Current; // 다음에 갈곳
		Next = Next + Dir[dir]; //방향 이동. Right->Down->Left->Up
		if (Next.x < 0 || Next.y < 0 || Next.x >= MAX || Next.y >= MAX) //이동 할곳이 정확한지
		{
			continue;//현재 방향 다음 방향 이동
		}

		if (maze[Next.y][Next.x] == WAY) //미리 가보는곳이 갈수 있는지?
		{
			Current = Next;
			return true;
		}
	}

	return false; //다음 갈곳이 없음
}

int main()
{
	//방향 정보 매핑 초기화
	Dir[static_cast<int>(Direction::Right)].x = 1;
	Dir[(int)Direction::Right].y = 0;

	Dir[(int)Direction::Down].x = 0;
	Dir[(int)Direction::Down].y = 1;

	Dir[(int)Direction::Left].x = -1;
	Dir[(int)Direction::Left].y = 0;

	Dir[(int)Direction::Up].x = 0;
	Dir[(int)Direction::Up].y = -1;

	Vector2 Current;

	stack<Vector2> EscapeMap;

	//알고리즘 시작
	while (true)
	{
		maze[Current.y][Current.x] = PATH; //현재 위치 지도에 표시
		if (Current.x == MAX - 1 && Current.y == MAX - 1) 
		{
			//목적지 도착 하면 끝
			break;
		}
		else if (CanMove(Current)) //다음 위치 이동 해보기
		{
			//다음 위치가 생겼음
			//현재 기록
			EscapeMap.push(Current);
		}
		else
		{
			if (EscapeMap.empty())
			{
				cout << "탈출불가" << endl;
				break;
			}
			else
			{
				maze[Current.y][Current.x] = BLOCK; //현재 위치는 길 막힘
				Current = EscapeMap.top(); //이전위치 복원
				EscapeMap.pop();
			}
		}
	}


	for (int y = 0; y < MAX; ++y)
	{
		for (int x = 0; x < MAX; ++x)
		{
			cout << maze[y][x] << " ";
		}
		cout << endl;
	}



	return 0;
}