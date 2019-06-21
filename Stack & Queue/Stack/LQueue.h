#pragma once
#include "LList.h"

template<typename T>
class LQueue
{
public:
	LQueue()
	{

	}
	virtual ~LQueue()
	{

	}

	void Push(T NewValue)
	{
		Data.PushBack(NewValue);
	}

	void Pop()
	{
		if (Data.GetSize() < 1)
		{
			return;
		}
		Data.Erase(Data.Begin());
	}

	T Front()
	{
		if (Data.GetSize() < 1)
		{
			return 0;
		}
		return (*Data.Begin())->Value;
	}

	T Back()
	{
		if (Data.GetSize() < 1)
		{
			return 0;
		}

		return (*Data.RBegin())->Value;
	}

	unsigned int GetSize()
	{
		return Data.GetSize();
	}


protected:
	LList<T> Data;
};

