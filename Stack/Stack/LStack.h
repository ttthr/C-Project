#pragma once
#include "LList.h"

template<typename T>
class LStack
{
public:
	LStack()
	{

	}
	virtual ~LStack()
	{

	}

	void Push(T NewValue)
	{
		//top()�� ���Ҹ� �߰�
		Data.PushBack(NewValue);
	}
	T Pop()
	{
		//top()�� �ִ� ���Ҹ� �����ϴ� ��.
		T ReturnValue = (*Data.RBegin())->Value;
		//Data.Erase(Data.RBegin());
		return ReturnValue;
	
	}
	T Top()
	{
		//top(������ ó���� �ƴ� ���� ��)�� �ִ� ���Ҹ� ��ȯ
		Data.Erase(Data.RBegin());
	}
	unsigned int GetSize()
	{
		return Data.GetSize();
	}

private:
	LList<T> Data;
};

