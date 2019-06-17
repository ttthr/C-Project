#pragma once
#include<iostream>
using namespace std;

class CMyVector
{
public:
	CMyVector();
	virtual ~CMyVector();
private:
	int* Data;
	size_t size;
	size_t position;
public:
	void PushBack(int _pushback);
	int operator[](size_t _Getposition);
	int GetDataSize() { return size; }
	int GetPosition() { return position; }
	ostream& operator<<(ostream& _cout);
};


