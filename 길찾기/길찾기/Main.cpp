#include<iostream>
#include<string>
#include<bitset>
using namespace std;

////재귀함수
////숫자 더하기
////문자열 거꾸로 찍기
//// 10진수 2진수로 출력
//
//// 피보나치 구현해볼것.
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
//	////숫자가 들어오면
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
////탐색함수
////찾으면 찾은 인덱스
////없으면 -1
////for문
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
////링커시브로 
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
// 길찾는 함수
bool FindMaze(int x, int y)
{
	//범위 체크
	if (x < 0 || y < 0 || x > MAX - 1 || y > MAX - 1)
	{
		return false;
	}
	//길이 아니면
	else if (maze[y][x] != WAY)
	{
		return false;
	}
	//목적지 이면
	else if (x == MAX - 1 && y == MAX - 1)
	{
		//지도에 표시
		maze[y][x] = PATH;
		return true;
	}
	//이동
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
	//시작값주기
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
	//	//cout << "숫자 입력: ";
	//	//cin >> num;
	//
	//	//Result += Sum(num);
	//
	//	//cout << "최종합: ";
	//	//cout << Result << endl;
	//
	//
	//	//char cString[1024]{ 0 };
	//	//cout << "문자입력: ";
	//	//cin >> cString;
	//
	//	//cout << "바뀐 문자열 출력: ";
	//	//ReverseString(cString);
	//
	//	//cout << endl;
	//	//int num2 = 0;
	//
	//	//cout << "십진수 입력: ";
	//	//cin >> num2;
	//	//
	//	//cout << "이진수 값 출력:";
	//	//binary(num2);

//
////기본
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
//// 길찾는 함수
//bool FindMaze(int x, int y)
//{
//	//범위 체크
//	if (x < 0 || y < 0 || x > MAX - 1 || y > MAX - 1)
//	{
//		return false;
//	}
//	//길이 아니면
//	else if (maze[y][x] == 1)
//	{
//		return false;
//	}
//	//목적지 이면
//	else if (x == MAX - 1 && y == MAX - 1)
//	{
//		return true;
//	}
//	//이동
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
//	//시작값주기
//	FindMaze(0, 0);
//
//}