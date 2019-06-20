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

void CMyList::Push_Back(int NewValue)
{
	Node* NewNode = new NODE();
	NewNode->Value = NewValue;

	// 헤드가 테일이면
	if (Head == Tail)
	{
		Head->Next = NewNode;
		NewNode->Next = Tail;
	}
	else //헤드가 테일이 아닐 때
	{
		for (FindNode = Head; FindNode->Next != Tail; FindNode = FindNode->Next)
		{
			//순회
	
		}
		////찾은 노드 다음을 NewNode;
		FindNode->Next = NewNode;
		////NewNode 는 테일
		NewNode->Next = Tail;


	}

}

void CMyList::insert(int NewValue, int SearchValue)
{
	Node* NewNode = new Node();
	NewNode->Value = NewValue;
	NewNode = Find(SearchValue);
	
	if (NewNode != nullptr)
	{
		Node* Next = NewNode->Next;
		NewNode->Next = NewNode;

		NewNode->Next = Next;
	}
}

Node * CMyList::Find(int SearchValue)
{
	Node* insertNode = new Node();
	insertNode->Value = SearchValue;

	for (Node* Find = insertNode->Next; Find != Tail; Find = Find->Next)
	{
		return Find;
	}
	return nullptr;
}


