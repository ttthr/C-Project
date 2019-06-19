#include<iostream>
#include<list>
using namespace std;

#include "CMyList.h"

//2019.06.19
//링크드리스트

int main()
{
	CMyList List;
	
	for (int i = 1; i < 10; ++i)
	{
		List.Insert(i);
	}
	for (NODE* current = List.Head; current != List.Tail; current = current->Next)
	{
		cout << current->Value << endl;
	}
	return 0;
}