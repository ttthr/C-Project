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

//int n = 0;
//
//cin >> n;
//
//while (n != 0)
//{
//	n % 2; //�������� ¦���� 0 Ȧ���� 1
//	n = n / 2; //�տ����� �ڿ����� ���� ��
//}


int main()
{

	vector<int> vInt;
	vInt.reserve(10);
	vector<int> vInt2;
	vInt2.reserve(10); //�ι�° �迭
	int n = 0;
	int binary = 0;

	cout << "���� ũ�⸦ �Է��ϼ���: ";
	cin >> n;

	cout << "ù��° �迭 ���ڸ� �Է��ϼ���: ";

	for (int i = 0; i < n; ++i)
	{
		vInt.push_back(i);
		cin >> vInt[i];
	}

	cout << "�ι�° �迭 ���ڸ� �Է��ϼ���: ";

	for (int i = 0; i < n; ++i)
	{
		vInt2.push_back(i);
		cin >> vInt2[i];
	}
	cout << "******************************" << endl;
	cout << "ù��° �迭 �� ���" << endl;
	for (int i = 0; i < n; ++i)
		cout << " " << vInt[i];

	cout << endl;

	cout << "�ι�° �迭 �� ���" << endl;
	for (int i = 0; i < n; ++i)
		cout << " " << vInt2[i];

	cout << endl;
	cout << "******************************" << endl;
	cout << "10���� ---> 2������ ���" << endl;

	bitset<5> buf;
	bitset<5> buf2;
	bitset<5> buf3;
	bitset<5> buf4;
	bitset<5> buf5;
	bitset<5> buf6;
	bitset<5> buf7;
	bitset<5> buf8;
	bitset<5> buf9;
	bitset<5> buf10;

	buf = vInt[0];
	cout << buf << " ";
	buf2 = vInt2[0];
	cout << buf2 << " ";
	buf3 = vInt[1];
	cout << buf3 << " ";
	buf4 = vInt2[1];
	cout << buf4 << " ";
	buf5 = vInt[2];
	cout << buf5 << " ";
	cout << endl;
	buf6 = vInt2[2];
	cout << buf6 << " ";
	buf7 = vInt[3];
	cout << buf7 << " ";
	buf8 = vInt2[3];
	cout << buf8 << " ";
	buf9 = vInt[4];
	cout << buf9 << " ";
	buf10 = vInt2[4];
	cout << buf10 << " ";



	cout << endl;

	cout << "******************************" << endl;

	cout << "������� ���" << endl;

	for (int j = 4; j >= 0; --j)
	{
		if (buf[j] || buf2[j] == 1)
			cout << "#";
		else
			cout << " ";

	}
	cout << endl;

	for (int j = 4; j >= 0; --j)
	{
		if (buf3[j] || buf4[j] == 1)
			cout << "#";
		else
			cout << " ";

	}
	cout << endl;
	for (int j = 4; j >= 0; --j)
	{
		if (buf5[j] || buf6[j] == 1)
			cout << "#";
		else
			cout << " ";

	}
	cout << endl;
	for (int j = 4; j >= 0; --j)
	{
		if (buf7[j] || buf8[j] == 1)
			cout << "#";
		else
			cout << " ";

	}

	cout << endl;
	for (int j = 4; j >= 0; --j)
	{
		if (buf9[j] || buf10[j] == 1)
			cout << "#";
		else
			cout << " ";

	}






	

	//cout << endl;
	//cout << "ù��° �迭 ������ ��ȯ" << endl;

	//while (n != 0)
	//{
	//	vInt.push_back(binary % 2);
	//	binary = binary / 2;
	//}

	//for (int i = vInt.size() - 1; i >= 0; --i)
	//	cout << vInt[i];


	//for (int i = 0; i < n; ++i)
	//	cin >> vInt[i];

	//cout << "�� �� ���: ";
	//for (int i = 0; i < n; ++i)
	//	cout << " " << vInt[i];

	//cout << endl;
	//cout << "ù��° �迭 ������ ��ȯ" << endl;

	//for (int i = 0; n > 0; ++i)
	//{
	//	vInt[i] = binary % 2;
	//	binary = binary / 2;
	//	cout << vInt[i];
	//}

	
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