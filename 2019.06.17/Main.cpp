#include<iostream>
#include<vector>
using namespace std;

#include "CMyVector.h"

//2019.06.17 
//STL

int main()
{
	
	CMyVector pVec;

	for(int i =0 ; i < 100; ++i)
		pVec.PushBack(i);

	for (int i = 0; i < pVec.GetDataSize(); ++i)
		cout << pVec[i] << endl;
	for (int i = 0; i < pVec.GetDataSize(); ++i)
		cout << pVec[i] << endl;

	return 0;
}