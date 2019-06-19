#include <iostream>
#include <vector>

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
// 9223372036854775807 

int main()
{
	//cout << sizeof(uint64);
	vector<uint64> Storage;
	vector<uint64> NPOTStorage;
	int N = 0;
	uint64 X = 0;
	cout << "숫자 갯수 입력: ";
	cin >> N;

	//입력
	cout << "값 입력:";
	for (int i = 0; i < N; ++i)
	{
		cin >> X;
		Storage.push_back(X);
	}


	for (int count = 0; count < N; ++count)
	{
		//NPOT
		uint64 Temp = 1;
		for (int i = 0; i < 64; ++i)
		{
			Temp = (uint64)(1ULL << i);

			if (Temp >= Storage[count])
			{
				NPOTStorage.push_back(Temp);
				break;
			}
		}
	}

	uint64 Result = NPOTStorage[0];
	for (unsigned int i = 1; i < NPOTStorage.size(); ++i)
	{
		//cout << NPOTStorage[i] << " ^ ";
		Result ^= NPOTStorage[i];
	}
	cout << Result << endl;

	return 0;
}
