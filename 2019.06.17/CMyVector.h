#pragma once
#include<iostream>
#include<memory.h>
using namespace std;


class CMyVector
{
public:
	CMyVector();
	virtual ~CMyVector();
private:
	int* Data;
	size_t StorageSize;
	size_t position;
public:
	void PushBack(int _pushback);
	int operator[](size_t _Getposition);
	int GetDataSize() { return StorageSize; }
	int GetPosition() { return position; }
};


