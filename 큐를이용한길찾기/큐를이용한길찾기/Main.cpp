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

	//4���� �����̱�
	for (int dir = (int)Direction::right; dir <= (int)Direction::up; ++dir)
	{
		Next = Current; // ������ ����
		Next = Next + Dir[dir]; //���� �̵�. Right->Down->Left->Up
		if (Next.x < 0 || Next.y < 0 || Next.x >= MAX || Next.y >= MAX) //�̵� �Ұ��� ��Ȯ����
		{
			continue;//���� ���� ���� ���� �̵�
		}

		if (maze[Next.y][Next.x] == WAY) //�̸� �����°��� ���� �ִ���?
		{
			Current = Next;
			return true;
		}
	}

	return false; //���� ������ ����
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
				cout << "Ż��" << endl;
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

	//���� ���� ���� �ʱ�ȭ
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

//1.ť�����
//ó�� ���� ��ġ�� (���ڸ� ����, 100)
//�ʱ�ȭ �Ҷ� Ż�ⱸ ��ã��
//Ž��(ť�� ������� ������)
/*{
	ť���� ����������(������ġ)
	����(��ġ) ��������
	4�����̵�(�ݺ���)
	{
	   �̵�����()
	   {
			������ġ(=)�� ���� ��ġ + 1 ���ֱ�
			������ġ(=)�� �������ΰ�?
			{
				-> �׷� Ż��
			}
			//�ƴϸ� ������ġ ���
			{
				ť���ٰ� ���
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