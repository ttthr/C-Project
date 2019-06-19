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
public:
	void Insert(int NewValue);
	void NewInsert(NODE* _node, int NewValue);


};

