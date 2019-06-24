#include<iostream>
#include<string>
#include<bitset>
using namespace std;

//재귀함수
//숫자 더하기
//문자열 거꾸로 찍기
// 10진수 2진수로 출력
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
	////숫자가 들어오면
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
	cout << "숫자 입력: ";
	cin >> num;

	Result += Sum(num);

	cout << "최종합: ";
	cout << Result << endl;


	char cString[1024]{ 0 };
	cout << "문자입력: ";
	cin >> cString;

	cout << "바뀐 문자열 출력: ";
	ReverseString(cString);

	cout << endl;
	int num2 = 0;

	cout << "십진수 입력: ";
	cin >> num2;
	
	cout << "이진수 값 출력:";
	binary(num2);


	return 0;
}