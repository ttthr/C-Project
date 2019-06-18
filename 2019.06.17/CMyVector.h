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
			//저장소 새로 생성, 추가(2배씩늘린다.)
			T* temp = new T[StorageSize * 2];

			memcpy(temp, Data, position * sizeof(T)); //한번에 메모리 카피, 맨 끝 바이트 단위

			delete[] Data;
			Data = temp;
			StorageSize = StorageSize * 2;
			Data[position++] = _pushback;
		}
		else
		{
			//늘릴필요 없어서 걍 값 넣음
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
		//1. 인자로 삭제할 부분의 시작과 끝이 들어온다. 
		//2. 원래 벡터 erase는 v.erase(v.begin(), v.end()); ** 시작부터 끝까지 지우는 개념 ***
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
	//수업
	//bool my_Erase(size_t index)
	//{
	//	if (index > position || index < 0)
	//	{
	//		cout << "못지웁니다." << endl;
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


