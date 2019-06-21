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
		//top()에 원소를 추가
		Data.PushBack(NewValue);
	}
	T Pop()
	{
		//top()에 있는 원소를 삭제하는 곳.
		T ReturnValue = (*Data.RBegin())->Value;
		//Data.Erase(Data.RBegin());
		return ReturnValue;
	
	}
	T Top()
	{
		//top(스택의 처음이 아닌 가장 끝)에 있는 원소를 반환
		Data.Erase(Data.RBegin());
	}
	unsigned int GetSize()
	{
		return Data.GetSize();
	}

private:
	LList<T> Data;
};

