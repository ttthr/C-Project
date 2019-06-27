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
	vector2(): x(0), y(0) { }

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
int visitmaze[MAX][MAX]
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

int Check(vector2 p) {

	return !(p.x < MAX - 1 || p.x< 0 || p.y < MAX - 1 || p.y < 0) ? true : false;
}
bool CanMove(vector2& Current)
{
	vector2 Next;

	//4방향 움직이기
	for (int dir = (int)Direction::right; dir <= (int)Direction::up; ++dir)
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

void FindMaze(vector2& pos)
{
	queue<vector2> my_queue;

	vector2 TempPos;

	TempPos = pos;
	my_queue.push(TempPos);
	visitmaze[TempPos.y][TempPos.x] = 100;

	while (!my_queue.empty())
	{
		TempPos = my_queue.front();
		my_queue.pop();

		int CurrentLevel = visitmaze[TempPos.y][TempPos.x];
	
		for (int dir = (int)Direction::right; dir <= (int)Direction::up; ++dir)
		{
			TempPos = TempPos + Dir[dir];
			//TempPos.y = TempPos.y + Dir[dir].y;
			//TempPos.x = TempPos.x + Dir[dir].x;
			
			if (TempPos.x < 0 || TempPos.y < 0 || TempPos.x >= MAX || TempPos.y >= MAX)
			{
				break;
			}
			if (TempPos.x == MAX - 1 && TempPos.y == MAX - 1)
			{
				cout << "탈출" << endl;
				break;
			}
			
			else if (visitmaze[TempPos.y][TempPos.x] == WAY)
			{			
				visitmaze[TempPos.y][TempPos.x] = CurrentLevel + 1;
				my_queue.push(TempPos);
	
			}
			
		}	
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

	RenderMap();
	
	vector2 pos;
	FindMaze(pos);

	cout << endl;

	for (int y = 0; y < MAX - 1; ++y)
	{
		for (int x = 0; x < MAX - 1; ++x)
		{
			cout << visitmaze[y][x] << " ";
		}
		cout << endl;
	}

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
//}*/
//
//
// Check(CurrentPos)&& !visitmaze[CurrentPos.y][CurrentPos.x] && maze[CurrentPos.y][CurrentPos.x]
//if (checkRangeOver(cur) && !visited[cur.y][cur.x]
//	&& edge[cur.y][cur.x]) {
//