#include<iostream>
#include<string>
#include<bitset>
using namespace std;

//����Լ�
//���� ���ϱ�
//���ڿ� �Ųٷ� ���
// 10���� 2������ ���
int Sum(int _num)
{
	if (_num <= 1)
		return 1;
	else
	{
		return _num + Sum(_num - 1);
	}
}

void ReverseString(char* _cString)
{
	if (*_cString == '\0')
	{
		return;
	}
	else
	{
		ReverseString(_cString + 1);
		cout << *_cString;
	}
}

int binary(int _num2)
{

	int temp = 0;
	////���ڰ� ������
	if (_num2 > 0)
	{
		temp = _num2;
		binary(temp / 2);
		cout << temp % 2;

	}
	return 0;
}

int main()
{

	int num = 0;
	int Result = 0;
	cout << "���� �Է�: ";
	cin >> num;

	Result += Sum(num);

	cout << "������: ";
	cout << Result << endl;


	char cString[1024]{ 0 };
	cout << "�����Է�: ";
	cin >> cString;

	cout << "�ٲ� ���ڿ� ���: ";
	ReverseString(cString);

	cout << endl;
	int num2 = 0;

	cout << "������ �Է�: ";
	cin >> num2;
	
	cout << "������ �� ���:";
	binary(num2);


	return 0;
}