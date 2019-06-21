#include "AStack.h"

//astack::astack(int defalutsize)
//
//{
//	maxsize = defalutsize;
//	data = new int[maxsize];
//	size = 0;
//	cursor = 0;
//}
//
//
//astack::~astack()
//{
//	delete[] data;
//}
//
//void astack::push(int _data)
//{
//	if (size < maxsize) // size < maxsize
//	{
//		data[cursor] = _data;
//		size++;
//		cursor++;
//	}
//}
//
//int astack::pop()
//{
//	if (size < 1)
//	{
//		return 0;
//	}
//	size--;
//	return data[--cursor];
//
//}
