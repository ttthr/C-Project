#include<iostream>
#include<vector>

using namespace std;

#include "CMyVector.h"

//2019.06.17 
//STL

int main()
{
	
	CMyVector pVec;

	for(int i =0 ; i < 10000; ++i)
		pVec.PushBack(i);

	for (int i = 0; i < pVec.GetPosition(); ++i)
		cout << pVec[i] << endl;
	

	return 0;
}