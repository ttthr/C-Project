#pragma once
#include<iostream>
#include<memory.h>
using namespace std;

template<typename T>

class CMyVector
{
public:
	CMyVector()
	{
		StorageSize = 100;
		position = 0;
		Data = new T[StorageSize];
	};
	virtual ~CMyVector()
	{
		delete[] Data;
	};
private:
	T* Data;
	size_t StorageSize;
	size_t size;
	size_t position;
public:
	void PushBack(T _pushback)
	{
		if (position == StorageSize)
		{
			//����� ���� ����, �߰�(2�辿�ø���.)
			T* temp = new T[StorageSize * 2];

			memcpy(temp, Data, position * sizeof(T)); //�ѹ��� �޸� ī��, �� �� ����Ʈ ����

			delete[] Data;
			Data = temp;
			StorageSize = StorageSize * 2;
			Data[position++] = _pushback;
		}
		else
		{
			//�ø��ʿ� ��� �� �� ����
			Data[position++] = _pushback;
		}
	};
	T operator[](size_t _Getposition)
	{
		return Data[_Getposition];
	};
	size_t GetDataSize() { return StorageSize; }
	size_t GetPosition() { return position; }
public:
	void Erase(T _EraseIndex)
	{
		for (int i = _EraseIndex + 1; i < position; ++i) {
			Data[i - 1] = Data[i];
		}
		position--;
	};
	void Erase(T _BegineErase, T _EndErase)
	{
		//1. ���ڷ� ������ �κ��� ���۰� ���� ���´�. 
		//2. ���� ���� erase�� v.erase(v.begin(), v.end()); ** ���ۺ��� ������ ����� ���� ***
		for (int i = _BegineErase + 1; i < _EndErase; ++i)
		{

		}
	};
public:
	void Insert(T _insert)
	{
		for (int i = 0; i < position; i++)
		{
			if (position == _insert)
			{
				Data[i] = _insert;

			}

		}
		//position++;
	}
public:
	//����
	//bool my_Erase(size_t index)
	//{
	//	if (index > position || index < 0)
	//	{
	//		cout << "������ϴ�." << endl;
	//		return false;
	//	}
	///*	for (int i = index; i < position - 1; ++i)
	//	{
	//		Data[i] = Data[i + 1];
	//	}*/
	//	memcpy(Data[index], Data[index + 1], (position - index) * sizeof(T));
	//	//position--;
	//	return true;
	//}
	/*bool InsertAfter(size_t index, T Value)
	{
		return false;
	}*/
};


