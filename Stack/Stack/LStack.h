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
	T Pop()
	{
		T ReturnValue = (*Data.RBegin())->Value;
		Data.Erase(Data.RBegin());
		return ReturnValue;
	}

	unsigned int GetSize()
	{
		return Data.GetSize();
	}

private:
	LList<T> Data;
};

