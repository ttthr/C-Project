#include "CMyList.h"



CMyList::CMyList()
{
	Head = new NODE();
	Tail = new NODE();
	Head->Next = Tail;
}


CMyList::~CMyList()
{


}

void CMyList::Insert(int NewValue)
{
	NODE* NewNode = new NODE;
	NewNode->Value = NewValue;

	Node* Find;

	for (Find = Head; Find->Next != Tail; Find = Find->Next)
	{

	}

	Find->Next = NewNode;
	NewNode->Next = Tail;

}

void CMyList::NewInsert(NODE * _node, int NewValue)
{
	NODE* NewNode = new NODE;
	NewNode->Value = NewValue;

}
