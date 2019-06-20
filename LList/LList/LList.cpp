#include "LList.h"



LList::LList()
{
	Head = new Node();
	Tail = new Node();
	Head->Next = Tail;
}


LList::~LList()
{
}

//1. 자료 없을때
//2. 자료 있을때
void LList::Insert(int NewValue)
{
	Node* NewNode = new Node();
	NewNode->Value = NewValue;

	//if (Head->Next == Tail)
	//{
	//	Head->Next = NewNode;
	//	NewNode->Next = Tail;
	//}
	//else
	//{
		Node* Find;
		for (Find = Head; Find->Next != Tail; Find = Find->Next)
		{
		}

		Find->Next = NewNode;
		NewNode->Next = Tail;
		
	//}
}

void LList::Insert(int NewValue, int SearchValue)
{
	Iterator InsertPositionIterator = Find(SearchValue);
	if (InsertPositionIterator != nullptr)
	{
		Node* NewNode = new Node();
		NewNode->Value = NewValue;

		Node* Next = (*InsertPositionIterator)->Next;

		(*InsertPositionIterator)->Next = NewNode;
		//추가 노드의 다음은 원래 노드의 다음
		NewNode->Next = Next;
	}
}

LList::Iterator LList::Find(int SearchValue)
{
	for (Iterator Current = Begin(); Current != End(); ++Current)
	{
		if ((*Current)->Value == SearchValue)
		{
			return Current;
		}
	}

	return nullptr;
}
