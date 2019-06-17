#include "CMyVector.h"



CMyVector::CMyVector()
	:size(100),
	position(0)
{

	Data = new int[size];

}
CMyVector::~CMyVector()
{
	delete[] Data;
}
void CMyVector::PushBack(int _pushback)
{
	if (position == size)
	{
		//����� ���� ����, �߰�(2�辿�ø���.)
		int* temp = new int[size * 2];
		for (int i = 0; i < size; ++i)
		{
			//�� ����
			temp[i] = Data[i];
		}
		delete[] Data;
		Data = temp;
		size = size * 2;
		Data[position++] = _pushback;
	}
	else
	{
		//�ø��ʿ� ��� �� �� ����
		Data[position++] = _pushback;
	}

	
}

int CMyVector::operator[](size_t _Getposition)
{
	return Data[_Getposition];
}

ostream & CMyVector::operator<<(ostream & _cout)
{
	return _cout;
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