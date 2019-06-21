#include<iostream>
using namespace std;
#include "Queue.h"

int main()
{
	Queue<int> q;

	q.Push(1);
	q.Push(2);
	q.Push(3);

	q.Pop();
	q.Pop();
	q.Pop();

	return 0;
}