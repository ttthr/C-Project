#include<iostream>
#include<string>
#include<bitset>
using namespace std;

////����Լ�
////���� ���ϱ�
////���ڿ� �Ųٷ� ���
//// 10���� 2������ ���
//
//// �Ǻ���ġ �����غ���.
//int Sum(int _num)
//{
//	if (_num <= 1)
//		return 1;
//	else
//	{
//		return _num + Sum(_num - 1);
//	}
//}
//
//void ReverseString(char* _cString)
//{
//	if (*_cString == '\0')
//	{
//		return;
//	}
//	else
//	{
//		ReverseString(_cString + 1);
//		cout << *_cString;
//	}
//}
//
//int binary(int _num2)
//{
//
//	int temp = 0;
//	////���ڰ� ������
//	if (_num2 > 0)
//	{
//		temp = _num2;
//		binary(temp / 2);
//		cout << temp % 2;
//
//	}
//	return 0;
//}
//
////Ž���Լ�
////ã���� ã�� �ε���
////������ -1
////for��
//int Search(int* Data, int Size, int Target)
//{
//	for (int i = 0; i < Size; ++i)
//	{
//		if (Data[i] == Target)
//		{
//			return i;
//		}
//	}
//
//	return -1;
//}
//int Search(int* Data, int Begin, int End, int Target)
//{
//	for (int i = Begin; i < End; ++i)
//	{
//		if (Data[i] == Target)
//		{
//			return i;
//		}
//	}
//
//	return -1;
//}
////��Ŀ�ú�� 
//
//int Search2(int* Data, int Begin, int End, int Target)
//{
//
//	if (Begin <= End)
//	{
//		if ( Target == Data[Begin])
//		{
//			return Begin;
//		}
//		else
//		{
//			return Search2(Data, Begin + 1, End, Target);
//		}
//	}
//	return -1;
//}
//

#define MAX 10
#define WAY 0
#define WALL 1
#define BLOCK 2
#define PATH 3
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
// ��ã�� �Լ�
bool FindMaze(int x, int y)
{
	//���� üũ
	if (x < 0 || y < 0 || x > MAX - 1 || y > MAX - 1)
	{
		return false;
	}
	//���� �ƴϸ�
	else if (maze[y][x] != WAY)
	{
		return false;
	}
	//������ �̸�
	else if (x == MAX - 1 && y == MAX - 1)
	{
		//������ ǥ��
		maze[y][x] = PATH;
		return true;
	}
	//�̵�
	else
	{
		maze[y][x] = PATH;

		if (FindMaze(x + 1, y))
		{
			//cout << "(" << x << "," << y << ")" << endl;
			return true;
		}
		else if (FindMaze(x, y + 1))
		{
			//cout << "(" << x << "," << y << ")" << endl;
			return true;
		}
		else if (FindMaze(x - 1, y))
		{
			//cout << "(" << x << "," << y << ")" << endl;
			return true;
		}
		else if (FindMaze(x, y - 1))
		{
			//cout << "(" << x << "," << y << ")" << endl;
			return true;
		}
		else
		{
			maze[y][x] = BLOCK;
			return false;
		}

	}

	return true;
}
void PrintMap()
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
	//���۰��ֱ�
	FindMaze(0, 0);
	PrintMap();

}

//	int Data[10]{ 1,2,3,4,5,6,7,8,9,10 };
	//	
	//	//cout << Data[Search(Data, 3, 10, 5)];
	//
	//	cout << Data[Search2(Data, 0, 9, 7)];
	//
	//	return 0;
	//}
	//
	//	//int num = 0;
	//	//int Result = 0;
	//	//cout << "���� �Է�: ";
	//	//cin >> num;
	//
	//	//Result += Sum(num);
	//
	//	//cout << "������: ";
	//	//cout << Result << endl;
	//
	//
	//	//char cString[1024]{ 0 };
	//	//cout << "�����Է�: ";
	//	//cin >> cString;
	//
	//	//cout << "�ٲ� ���ڿ� ���: ";
	//	//ReverseString(cString);
	//
	//	//cout << endl;
	//	//int num2 = 0;
	//
	//	//cout << "������ �Է�: ";
	//	//cin >> num2;
	//	//
	//	//cout << "������ �� ���:";
	//	//binary(num2);

//
////�⺻
//#define MAX 10
//
//
//int maze[MAX][MAX]
//{
//	{0,0,0,0,1,1,1,1,1,1},
//	{1,1,1,0,1,1,1,1,1,1},
//	{1,1,1,0,1,1,1,1,1,1},
//	{1,1,1,0,1,1,1,1,1,1},
//	{1,1,1,0,1,1,1,1,1,1},
//	{1,1,1,0,1,1,1,1,1,1},
//	{1,1,1,0,0,0,0,0,1,1},
//	{1,1,1,1,1,1,1,0,1,1},
//	{1,1,1,1,1,1,1,0,1,1},
//	{1,1,1,1,1,1,1,0,0,0}
//};
//// ��ã�� �Լ�
//bool FindMaze(int x, int y)
//{
//	//���� üũ
//	if (x < 0 || y < 0 || x > MAX - 1 || y > MAX - 1)
//	{
//		return false;
//	}
//	//���� �ƴϸ�
//	else if (maze[y][x] == 1)
//	{
//		return false;
//	}
//	//������ �̸�
//	else if (x == MAX - 1 && y == MAX - 1)
//	{
//		return true;
//	}
//	//�̵�
//	else
//	{
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
//
//	}
//
//	return true;
//}
//int main()
//{
//	//���۰��ֱ�
//	FindMaze(0, 0);
//
//}