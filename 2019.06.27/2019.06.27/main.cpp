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
	int high = begin;

	int index = begin;

	//시작부터 끝까지 돌건데
	for (int i = begin; i < end ; ++i)
	{
		//데이터의 비긴 인덱스랑 피봇인덱스 비교해서
		//피봇이 더 크면 비긴 인덱스랑 엔드 교환하고
		//인덱스 ++;
		// 10 , 2 , 19 
		// 19 , 2 , 10
		// index = 1;
		// 
		if (Data[index] <= pivot) 
		{
			Swap(Data[index], Data[end]);
			index++;
		}	
	}
	Swap(Data[index + 1], Data[end]);

	return index; // pivot의 인덱스..라
}

void QuickSort(int* Data, int begin, int end)
{
	if (begin < end) //시작이 end
	{
		int pivot = partition(Data, begin, end);
		QuickSort(Data, begin, pivot - 1);
		QuickSort(Data, pivot + 1, end);
	}
}
int main()
{
	int Data[10] = { 10 , 2 , 19 , 15};

	for (int i = 0; i < 4; ++i)
	{
		cout << Data[i] << " ";
	}

	QuickSort(Data, 0, 3);
	cout << endl;

	for (int i = 0; i < 4; ++i)
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
//return index + 1 ;//pivot 인덱스;