#include "CMyVector.h"


//template<class T>
//CMyVector<T>::CMyVector()
//	:StorageSize(100),
//	position(0)
//{
//	Data = new T[StorageSize];
//}
//
//template<class T>
//CMyVector<T>::~CMyVector()
//{
//	delete[] Data;
//}
//
//template<class T>
//void CMyVector<T>::PushBack(T _pushback)
//{
//	if (position == StorageSize)
//	{
//		//����� ���� ����, �߰�(2�辿�ø���.)
//		T* temp = new T[StorageSize * 2];
//		//for (int i = 0; i < size; ++i)
//		//{
//		//	//�� ����
//		//    temp[i] = Data[i];
//		//}
//		memcpy(temp, Data, position * sizeof(T)); //�ѹ��� �޸� ī��, �� �� ����Ʈ ����
//
//		delete[] Data;
//		Data = temp;
//		StorageSize = StorageSize * 2;
//		Data[position++] = _pushback;
//	}
//	else
//	{
//		//�ø��ʿ� ��� �� �� ����
//		Data[position++] = _pushback;
//	}
//
//	
//}
//template<class T>
//int CMyVector<T>::operator[](size_t _Getposition)
//{
//	return Data[_Getposition];
//}


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