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
	cout << "���ڿ� �Է�:";
	cin >> cString;

	int cStringSize = AStack<int>::my_strlen(cString);
	AStack<char> ReversChar(cStringSize);
	cout << "���ڿ�������: " << cStringSize << endl;

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