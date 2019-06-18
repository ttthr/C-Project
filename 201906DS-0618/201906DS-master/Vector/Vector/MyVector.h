#pragma once
#include <memory.h>

template<typename T>
class MyVector
{
public:
	MyVector();
	virtual ~MyVector();

	void PushBack(T NewValue);
	T operator[](size_t GetPos);

	int GetSize();

	bool Erase(size_t Index);
	bool InsertAfter(size_t Index, T Value);
	bool Clear();
private:
	T* Data;
	size_t StorageSize;
	size_t InsertPosition; 
	size_t Size;
};

template<typename T>
MyVector<T>::MyVector()
{
	StorageSize = 100;
	InsertPosition = 0;
	Size = 0;
	Data = new T[StorageSize];
}

template<typename T>
MyVector<T>::~MyVector()
{
	if (Data != nullptr)
	{
		delete[] Data;
		Data = nullptr;
	}
}

template<typename T>
void MyVector<T>::PushBack(T NewValue)
{
	if (Size >= StorageSize)
	{
		//저장소 새로 생성, 추가
		StorageSize = StorageSize * 2;

		T* Temp = new T[StorageSize];
		memcpy(Temp, Data, InsertPosition * sizeof(T));

		//예전에 작은 저장소 삭제
		delete[] Data;
		Data = Temp;
	}

	Data[InsertPosition++] = NewValue;
	Size++;
}

template<typename T>
T MyVector<T>::operator[](size_t GetPos)
{
	return Data[GetPos];
}

template<typename T>
int MyVector<T>::GetSize()
{
	return Size;
}

template<typename T>
bool MyVector<T>::Erase(size_t Index)
{
	if (Index < 0 || Index > InsertPosition)
	{
		return false;
	}

	memcpy(Data + Index, Data + (Index + 1), (Size - Index) * sizeof(T));

	InsertPosition--;
	Size--;

	return true;
}

template<typename T>
bool MyVector<T>::InsertAfter(size_t Index, T Value)
{
	if (Index < 0 || Index > InsertPosition)
	{
		return false;
	}

	if (Size >= StorageSize)
	{
		
		StorageSize = StorageSize * 2;
		T* Temp = new T[StorageSize];
		memcpy(Temp, Data, InsertPosition * sizeof(T));
		delete[] Data;
		Data = Temp;
	}

	memcpy(&Data[Index + 1], &Data[Index], (Size - Index) * sizeof(T));

	//for (int i = Size-1; i >= Index+1; --i)
	//{
	//	Data[i + 1] = Data[i];
	//}
	//Data[Index+1] = Value;

	Size++;
	InsertPosition++;

	return true;
}

template<typename T>
inline bool MyVector<T>::Clear()
{
	if ( Size && InsertPosition)
	{
		Size = 0;
		InsertPosition = 0;
		return true;

	}
	return false;
}


