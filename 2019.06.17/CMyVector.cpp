#include "CMyVector.h"



CMyVector::CMyVector()
	:StorageSize(100),
	position(0)
{
	Data = new int[StorageSize];
}
CMyVector::~CMyVector()
{
	delete[] Data;
}
void CMyVector::PushBack(int _pushback)
{
	if (position == StorageSize)
	{
		//저장소 새로 생성, 추가(2배씩늘린다.)
		int* temp = new int[StorageSize * 2];
		//for (int i = 0; i < size; ++i)
		//{
		//	//값 복사
		//    temp[i] = Data[i];
		//}
		memcpy(temp, Data, position * sizeof(int)); //한번에 메모리 카피, 맨 끝 바이트 단위

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

	
}

int CMyVector::operator[](size_t _Getposition)
{
	return Data[_Getposition];
}


   /*size++;
	if (Data == NULL)
	{
		Data = new int[1];
		Data[0] = _pushback;
		return;
	}
	int* temp = new int[size];

	for (int i = 0; i < size - 1; ++i)
	{
		temp[i] = Data[i];
	}
	delete[] Data;

	Data = temp;
	Data[size - 1] = _pushback;*/