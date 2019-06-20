#include "LList.h"



LList::LList()
{
	Head = new Node();
	Tail = new Node();
	Head->Next = Tail;
	Tail->Prev = Head;
}


LList::~LList()
{
}

void LList::PushBack(int NewValue)
{
	Node* NewNode = MakeNode(NewValue);

	if (NewNode)
	{
		NewNode->Prev = Tail->Prev;
		Tail->Prev = NewNode;
		NewNode->Next = Tail;
		NewNode->Prev->Next = NewNode;
	}
}

void LList::PushFront(int NewValue)
{
	Node* NewNode = MakeNode(NewValue);

	if (NewNode)
	{
		NewNode->Prev = Head;
		NewNode->Next = Head->Next;
		NewNode->Next->Prev = NewNode;
		Head->Next = NewNode;
	}
}

void LList::InsertAfter(LList::Iterator Where, int NewValue)
{
	if (Where != nullptr)
	{
		Node* NewNode = MakeNode(NewValue);

		//노드 연결
		NewNode->Next = (*Where)->Next;
		NewNode->Prev = (*Where);
		(*Where)->Next = NewNode;
		NewNode->Next->Prev = NewNode;
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

Node * LList::MakeNode(int NewValue)
{
	Node* NewNode = new Node();
	NewNode->Value = NewValue;

	return NewNode;
}
