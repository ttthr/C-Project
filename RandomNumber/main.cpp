#include <iostream>
#include <vector>

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
// 9223372036854775807 

int main()
{
	//cout << sizeof(uint64);
	vector<uint64> Storage;
	vector<uint64> NPOTStorage;
	int N = 0;
	uint64 X = 0;
	cout << "���� ���� �Է�: ";
	cin >> N;

	//�Է�
	cout << "�� �Է�:";
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
