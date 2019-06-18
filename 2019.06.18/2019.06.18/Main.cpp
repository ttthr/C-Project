#include<iostream>
#include<bitset>
#include<vector>
using namespace std;

//비트 마스킹
//int a = -1;
// //00000000 00000000 00000000 00000000
//a = a << 1; //한바퀴 돌아서 1
//
//cout << "a값: " << a << endl;


int main()
{
	vector<int> vInt;
	vInt.reserve(10);
	for (int i = 0; i < 10; ++i)
		vInt.push_back(i);

	cout << "숫자를 입력하세요: ";

	for (int i = 0; i < 5; ++i)
		cin >> vInt[i];

	cout << "들어간 값 출력: ";
	for (int i = 0; i < 5; ++i)
		cout << " " << vInt[i];



	
	//int num = 0;
	//int result[8]{ 0 };
	//int result2[8]{ 0 };


	//cout << "숫자 입력: ";
	//cin >> num;

	//for (int i = 0; num > 0; ++i)
	//{
	//	result[i] = num % 2;
	//	num = num / 2;	
	//}
	//for (int i = 0; i < 8; ++i)
	//{
	//	result2[i] = result[8 - i - 1];
	//	cout << result2[i];
	//}

	//cout << bitset<8>(num) << endl;
	
}