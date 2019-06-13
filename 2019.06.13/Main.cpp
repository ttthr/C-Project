#include<iostream>
using namespace std;

template<class T>

T add(T a, T b)
{
	return a + b;

}

template<class T>

//class로 템플릿만들때는
//헤더에 다 구현해야 된다.
//LRR LICHT
//OSC ( 공룡책)


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


	cout << "결과값: " << add(a, b) << endl;
	cout << "결과값: " << add(c, d) << endl;

	Cal<int> Calint;
	cout << Calint.add(a, b) << endl;
	Cal<float> Calfloat;
	cout << Calfloat.add(c, d) << endl;
	return 0;

}