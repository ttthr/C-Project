#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
// ����
// ���� X���� ũ�ų� ���� �� �� ���� ���� 2�� �¼�(2^n)�� NPOT(Next Power of Two)��� �� ��,
// �־��� ���� N���� NPOT�� ���Ͽ� ��� XOR�� ���� ���Ͻÿ�

// ����
// 1 < X < 2^63
// 1 <= N < 2^18

// ����
// �Է� 
// 3 : �����ǰ���
// 3
// 5
// 7

// ��� 
// 4
// 4 = 4 ^ 8 ^ 8 ( 4 xor 8 xor 8 )
// xor : ���߿� �ϳ��� 1�̸� 1 / �Ѵ� ������ 0 

// 9,223,372,036,854,775,807  ( (2^63) - 1 �� �� )
// ����� �����̷��ǰ� ������

typedef unsigned long long uint64;
//������ ��������
//type �����ϴ°��� ����� ��

int main()
{	
	//�Է¹��� ����
	int N = 0;
	uint64 X = 0;
	vector<uint64> vStorage;

	cout << "�����Է�: ";
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

//----------------���� ���� ���� �ڵ� -----------------//
	//unsigned long long inputNum;
	//unsigned long long XEnd = 1;

	//XEnd = ((XEnd << 63) - 1);
	//cout << "�Է��� ���� ����: ";
	//cin >> inputNum;

	//unsigned long long* X = new unsigned long long[inputNum];

	//cout << "�� �Է�: ";
	//for (int i = 0; i < inputNum; ++i)
	//	cin >> X[i];

	//for(int i = 0 ; i < inputNum; ++i)
	//{
	//	if (0 <= X[i] || X[i] < XEnd)
	//	{
	//		//���� X���� ũ�ų� ���� �� �� ���� ���� 2�� �¼�(2^n)
	//		//�־��� ���� N���� NPOT�� ���Ͽ� ��� XOR
	//		cout << "��: " << X[i] << endl;

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