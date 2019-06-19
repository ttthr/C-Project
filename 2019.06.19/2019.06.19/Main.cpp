#include<iostream>
#include<string>
#include<bitset>
#include<algorithm>
using namespace std;


int main()
{	
	int n = 5;
	int arr[5] = { 9,20,28,18,11 };
	int arr2[5] = { 30,1,21,17,28 };
	int Resultarr[5];

	string Result[5];

	for (int i = 0; i < n; ++i)
	{
		Resultarr[i] = arr[i] | arr2[i];
	}

	for (int i = 0; i < n; ++i)
	{
		Result[i] = bitset<5>(Resultarr[i]).to_string();
		replace(Result[i].begin(), Result[i].end() , '1','#' );
		replace(Result[i].begin(), Result[i].end(), '0', ' ');
		cout << Result[i] << endl;
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