#pragma once
#include"LList.h"

template<typename T>

class LStack
{
public:
	LStack() {};
	virtual ~LStack() {};
private:
	LList<T> Data;
public:
	void Push(T NewValue)
	{
		Data.PushBack(NewValue);
	};
	T Pop()
	{  
		//삭제 저장할 값
		T ReturnValue = (*Data->rBegin())->Value;
		Data.Erase(Data.RBegin());
		return ReturnValue;
	};
	unsigned int GetSize() {
		return 10;
		//리스트사이즈 
	}
	static int my_strlen(char* _len)
	{
		int Count = 0;
		while (_len[Count] != '\0')
		{
			Count++;
		}
		return Count;
	}
};

