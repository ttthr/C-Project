#include<iostream>
using namespace std;

template<class T>

T add(T a, T b)
{
	return a + b;

}

template<class T>

//class�� ���ø����鶧��
//����� �� �����ؾ� �ȴ�.
//LRR LICHT
//OSC ( ����å)


class Cal
{
public:
	T add(T a, T b)
	{
		return a + b;

	}
};

int main()
{
	int a = 2;
	int b = 3;
	float c = 2.3f;
	float d = 1.3f;


	cout << "�����: " << add(a, b) << endl;
	cout << "�����: " << add(c, d) << endl;

	Cal<int> Calint;
	cout << Calint.add(a, b) << endl;
	Cal<float> Calfloat;
	cout << Calfloat.add(c, d) << endl;
	return 0;

}