#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
// 문제
// 숫자 X보다 크거나 같은 수 중 가장 적은 2의 승수(2^n)를 NPOT(Next Power of Two)라고 할 때,
// 주어진 숫자 N개의 NPOT을 구하여 모두 XOR한 값을 구하시오

// 조건
// 1 < X < 2^63
// 1 <= N < 2^18

// 예시
// 입력 
// 3 : 숫자의갯수
// 3
// 5
// 7

// 출력 
// 4
// 4 = 4 ^ 8 ^ 8 ( 4 xor 8 xor 8 )
// xor : 둘중에 하나가 1이면 1 / 둘다 같으면 0 

// 9,223,372,036,854,775,807  ( (2^63) - 1 의 값 )
// 입출력 리다이렉션과 파이프

typedef unsigned long long uint64;
//범위가 정해지면
//type 지정하는것을 물어보는 것

int main()
{	
	//입력받을 숫자
	int N = 0;
	uint64 X = 0;
	vector<uint64> vStorage;

	cout << "숫자입력: ";
	cin >> N;

	for (int i = 0; i < N ; ++i)
	{
		cin >> X;
		vStorage.push_back(X);
	}


	return 0;
}



















//unsigned long long Pow(unsigned long long _base, unsigned long long _input)
//{
//	unsigned long long res = 1;
//	while (_input)
//	{
//		if (_input & 1)
//			res *= _base;
//		_input >>= 1;
//		_base *= _base;
//	}
//	return res;
//
//}

//----------------내가 구현 중인 코드 -----------------//
	//unsigned long long inputNum;
	//unsigned long long XEnd = 1;

	//XEnd = ((XEnd << 63) - 1);
	//cout << "입력할 숫자 갯수: ";
	//cin >> inputNum;

	//unsigned long long* X = new unsigned long long[inputNum];

	//cout << "값 입력: ";
	//for (int i = 0; i < inputNum; ++i)
	//	cin >> X[i];

	//for(int i = 0 ; i < inputNum; ++i)
	//{
	//	if (0 <= X[i] || X[i] < XEnd)
	//	{
	//		//숫자 X보다 크거나 같은 수 중 가장 적은 2의 승수(2^n)
	//		//주어진 숫자 N개의 NPOT을 구하여 모두 XOR
	//		cout << "값: " << X[i] << endl;

	//	}
	//	else
	//	{
	//		cout << "!!!!!!!!!" << endl;
	//		break;
	//	}

	//}
	//
	//delete[] X;
	//X = nullptr;