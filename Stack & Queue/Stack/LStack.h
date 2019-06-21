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
		Data.PushBack(NewValue);
	}

	T Top()
	{
		T ReturnValue = (*Data.RBegin())->Value;
		return ReturnValue;
	}

	void Pop()
	{
		Data.Erase(Data.RBegin());
	}

	unsigned int GetSize()
	{
		return Data.GetSize();
	}

private:
	LList<T> Data;
};

