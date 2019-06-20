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

//1. �ڷ� ������
//2. �ڷ� ������
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
		//�߰� ����� ������ ���� ����� ����
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
