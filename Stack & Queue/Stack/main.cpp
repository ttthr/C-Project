#include <iostream>
#include "AStack.h"
#include "LStack.h"
#include <stdlib.h>
#include <stack>
#include <queue>
#include "AQueue.h"
#include "LQueue.h"

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
//	char Buffer[1024] = { 0 };
//
//	cin.getline(Buffer, 1024);
//
//	unsigned int Size = strlen_s(Buffer, 1024);
//
//	queue<int> q;
//
//	//  3   2    1
//
//	q.push(1);
//	q.push(2);
//	q.push(3);
//
//	q.pop();
//	q.size();
//
//	cout << q.front() << endl;
//	cout << q.back() << endl;
//
////	q.push();
//
//	
//
//	//LStack<char> ReverseStack;
//	//AStack<char> ReverseStack;
//	stack<char> ReverseStack;
//
//	for (unsigned int i = 0; i < Size; ++i)
//	{
//		//ReverseStack.Push(Buffer[i]);
//		ReverseStack.push(Buffer[i]);
//	}
//
//	for (unsigned int i = 0; i < Size; ++i)
//	{
//		//cout << ReverseStack.Top();
//		//ReverseStack.Pop();
//		cout << ReverseStack.top();
//		ReverseStack.pop();
//	}
//
	//AQueue<int> Q(3);
	LQueue<int> Q;

	Q.Push(1);
	Q.Push(2);
	Q.Push(3);
	cout << Q.Front() << endl;
	Q.Pop();
	Q.Push(4);
	Q.Push(5);

	cout << Q.Front() << endl;
	Q.Pop();
	cout << Q.Front() << endl;
	Q.Pop();
	cout << Q.Front() << endl;
	Q.Pop();
	cout << Q.Front() << endl;
	Q.Pop();



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