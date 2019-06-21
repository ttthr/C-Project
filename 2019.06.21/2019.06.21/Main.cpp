#include<iostream>
using namespace std;

#include "AStack.h"
#include "LList.h"
#include "LStack.h"

int my_strlen(char* _len)
{
	int Count = 0;
	while (_len[Count] != '\0')
	{
		Count++;
	}
	return Count;
}

int main()
{
	AStack<int> StackInt;
	
	char cString[1024]{ 0 };
	cout << "문자열 입력:";
	cin >> cString;

	int cStringSize = AStack<int>::my_strlen(cString);
	AStack<char> ReversChar(cStringSize);
	cout << "문자열사이즈: " << cStringSize << endl;

	for (int i = 0; i < cStringSize; ++i)
	{
		ReversChar.Push(cString[i]);
	}

	for (int i = 0; i < cStringSize; ++i)
	{
		cout << ReversChar.Pop();
	}


	/*for (int i = 0; i < 10; ++i)
	{
		StackInt.Push(i);
	}

	for (int i = 0; i < 10; ++i)
	{
		cout << StackInt.Pop() << endl;
	}
*/

	return 0;

}