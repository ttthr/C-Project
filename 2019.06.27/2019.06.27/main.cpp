#include<iostream>
using namespace std;


void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


void BubbleSort(int* Data, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - 1; ++j)
		{
			if (Data[j] > Data[j + 1])
			{
				Swap(Data[j], Data[j + 1]);
			}
			
		}
	}
}

int partition(int* Data, int begin, int end)
{
	int pivot = Data[end];
	int index = begin - 1;
	
	//���ۺ��� ������ ���ǵ�
	for (int i = begin; i < end  - 1 ; ++i)
	{
		//�������� ��� �ε����� �Ǻ��ε��� ���ؼ�
		//�Ǻ��� �� ũ�� ��� �ε����� ���� ��ȯ�ϰ�
		//�ε��� ++;
		// 10 , 2 , 19 
		// 19 , 2 , 10
		// index = 1;
		// 
		if (Data[i] < pivot) 
		{
			++index;
			Swap(Data[index], Data[i]);
		}

		
	}
	Swap(Data[index + 1] , Data[end]);


	return index + 1; // pivot�� �ε���..��
}

void QuickSort(int* Data, int begin, int end)
{
	if (begin < end) //������ end
	{
		int pivot = partition(Data, begin, end);
		QuickSort(Data, begin, pivot - 1);
		QuickSort(Data, pivot + 1, end);
	}
}
int main()
{
	int Data[10] = { 10 , 19 , 3, 1 , 2};

	for (int i = 0; i < 5; ++i)
	{
		cout << Data[i] << " ";
	}

	QuickSort(Data, 0, 4);
	cout << endl;

	for (int i = 0; i < 5; ++i)
	{
		cout << Data[i] << " ";
	}



	return 0;
}


//for (int i = index; i < end; ++i)
//{
//	if (Data[end] <= pivot)
//	{
//		Swap(Data[index], Data[end]);
//	}
//}
//Swap(Data[index + 1], Data[end]);
//return index + 1 ;//pivot �ε���;