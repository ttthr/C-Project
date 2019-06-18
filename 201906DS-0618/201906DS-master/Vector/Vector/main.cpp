#include <iostream>
#include <vector>
#include "MyVector.h"
#include <time.h>


int main()
{
	MyVector <int> v;

	for (int i = 0; i < 5; ++i)
	{
		v.PushBack(i );
	}

	v.InsertAfter(1, 10);

	for (int i = 0; i < v.GetSize(); ++i)
	{
		std::cout << v[i] << std::endl;
	}

	v.Clear();


	return 0;
}