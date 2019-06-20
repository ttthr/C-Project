#pragma once

typedef class Node
{
public:
	int Value;
	Node* Next;
}NODE;
class CMyList
{
public:
	CMyList();
	virtual ~CMyList();
public:
	NODE* Tail;
	NODE* Head;
	Node* FindNode = nullptr;
public:
	void Push_Back(int NewValue);
	void insert(int NewValue, int SearchValue);
	Node* Find(int SearchValue);

};

