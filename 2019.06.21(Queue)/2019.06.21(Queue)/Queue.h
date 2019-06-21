#pragma once
#include<iostream>
using namespace std;

template <typename T>

class Queue
{
public:
	Queue(T _Value = 10) 
	{
		maxsize = _Value;
		Data = new T[maxsize];
		front = 0;
		rear = 0;
		size = 0;
		count = 0;
	};
	virtual ~Queue() { delete[] Data; Data = nullptr; };
private:
	T* Data;
	int front;
	int rear;
	int size;
	int maxsize;
	int count;
public:
	void Push(T _Data)
	{
		Data[rear] = _Data;
 
	};
	void Back(T _Data)
	{

	};
	void Pop()
	{

	};
	T& Front()
	{
		return nullptr;
	};
	int GetSize() { return size; }


};

