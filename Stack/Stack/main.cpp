#include <iostream>
#include "AStack.h"
#include "LStack.h"
#include <stdlib.h>
#include <stack>
using namespace std;

unsigned int strlen_s(char* Data, int Size);

int a()
{
	return 1;
	//return a();
}

int main()
{
//	a();
	char Buffer[1024] = { 0 };

	cin.getline(Buffer, 1024);

	unsigned int Size = strlen_s(Buffer, 1024);

	LStack<char> ReverseStack;
	//AStack<char> ReverseStack;

	for (unsigned int i = 0; i < Size; ++i)
	{
		ReverseStack.Push(Buffer[i]);
	}

	for (unsigned int i = 0; i < Size; ++i)
	{
		cout << ReverseStack.Pop();
	}


	return 0;
}

//Hello\0
unsigned int strlen_s(char* Data, int Size)
{
	for (int i = 0; i < Size; ++i)
	{
		if (Data[i] == '\0')
		{
			return i;
		}
	}

	return 0;
}