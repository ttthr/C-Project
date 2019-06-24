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
	};
	virtual ~Queue() 
	{
		if (Data != nullptr)
		{
			delete[] Data;
			Data = nullptr;
		}
	};
private:
	T* Data;
	int front;
	int rear;
	int size;
	int maxsize;
public:
	void Push(T _Data)
	{
		if (size >= maxsize)
			return;
		Data[rear] = _Data;
		rear++;
		size++;

	};
	void Back(T _Data)
	{

	};
	void Pop()
	{

	};
	T Front()
	{
		return 0;
	};
	int GetSize() { return size; }


};

