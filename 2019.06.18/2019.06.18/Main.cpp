#include<iostream>
#include<bitset>
#include<vector>
using namespace std;

//��Ʈ ����ŷ
//int a = -1;
// //00000000 00000000 00000000 00000000
//a = a << 1; //�ѹ��� ���Ƽ� 1
//
//cout << "a��: " << a << endl;


int main()
{
	vector<int> vInt;
	vInt.reserve(10);
	for (int i = 0; i < 10; ++i)
		vInt.push_back(i);

	cout << "���ڸ� �Է��ϼ���: ";

	for (int i = 0; i < 5; ++i)
		cin >> vInt[i];

	cout << "�� �� ���: ";
	for (int i = 0; i < 5; ++i)
		cout << " " << vInt[i];



	
	//int num = 0;
	//int result[8]{ 0 };
	//int result2[8]{ 0 };


	//cout << "���� �Է�: ";
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