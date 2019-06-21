#pragma once
template<typename T>
class AStack
{
public:
	AStack(unsigned int DefaultSize = 10)
	{
		MaxSize = DefaultSize;
		Data = new T[MaxSize];
		Size = 0;
		Cursor = 0;
	}

	virtual ~AStack()
	{
		delete[] Data;
	}


	void Push(T NewData)
	{
		if (Size < MaxSize)
		{
			Data[Cursor] = NewData;
			Size++;
			Cursor++;
		}
	}

	T Top()
	{
		if (Size < 1)
		{
			return 0;
		}

		return Data[Cursor-1];
	}

	void Pop()
	{
		if (Size < 1)
		{
			return;
		}

		Size--;
		--Cursor;
	}

	unsigned int GetSize()
	{
		return Size;
	}

private:
	T* Data;
	unsigned int Cursor;
	unsigned int Size;
	unsigned int MaxSize;
};