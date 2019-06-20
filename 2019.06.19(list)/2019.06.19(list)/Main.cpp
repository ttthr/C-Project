#include<iostream>
#include<list>
using namespace std;

#include "CMyList.h"

//2019.06.19
//링크드리스트

int main()
{
	CMyList List;
	List.Push_Back(1);
	List.Push_Back(2);
	List.insert(2, 3);
	

	
	for (NODE* current = List.Head; current != List.Tail; current = current->Next)
	{
		cout << current->Value << endl;
	}
	return 0;
}