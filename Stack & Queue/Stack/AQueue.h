#pragma once
template<typename T>
class AQueue
{
public:
	AQueue(unsigned int DefalteSize = 10)
	{
		Data = new T[DefalteSize];
		MaxSize = DefalteSize;
		Size = 0;
		Head = 0;
		Tail = -1;
	}

	virtual ~AQueue()
	{
		delete[] Data;
		Data = nullptr;
	}

	void Push(T NewValue)
	{
		if (Size >= MaxSize)
		{
			return;
		}

		Tail++;
		Tail = Tail % MaxSize;
		Data[Tail] = NewValue;
		Size++;

	}

	void Pop()
	{
		if (Size < 1)
		{
			return;
		}

		//Data[Head] = 0;
		Head++;
		Head = Head % MaxSize;
		Size--;
	}

	T Front()
	{
		if (Size < 1)
		{
			return 0;
		}

		return Data[Head];
	}

	T Back()
	{
		if (Size < 1)
		{
			return 0;
		}

		return Data[Tail];
	}

	inline unsigned int GetSize()
	{
		return Size;
	}

protected:
	T* Data;
	unsigned int MaxSize;
	unsigned int Size;

	int Head;
	int Tail;
};

