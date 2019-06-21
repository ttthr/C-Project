#pragma once
template <typename T>

class AStack
{
public:
	AStack(unsigned int DefalutSize = 10)
	{
		MaxSize = DefalutSize;
		Data = new T[MaxSize];
		Size = 0;
		Cursor = 0;
	};
	virtual ~AStack() {};
private:
	T* Data;
	unsigned int Cursor;
	unsigned int Size;
	unsigned int MaxSize;
public:
	void Push(T _Data)
	{
		if (Size < MaxSize) // size < maxsize
		{
			Data[Cursor] = _Data;
			Size++;
			Cursor++;
		}
	};
	T Pop()
	{
		if (Size < 1)
		{
			return 0;
		}
		Size--;
		return Data[--Cursor];
	};
	unsigned int GetSize() { return Size; }

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

