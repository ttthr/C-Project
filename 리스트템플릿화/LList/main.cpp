#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include "LList.h"

using namespace std;

int main()
{
	list<int> a;

	LList<float> l;
	for (int i = 1; i <= 10; ++i)
	{
		l.PushBack(i *1.1f);
	}

	for (LList<float>::Iterator CurrentPosition = l.Begin(); CurrentPosition != l.End(); CurrentPosition++)
	{
		CurrentPosition = l.Erase(CurrentPosition);
	}

	for (LList<float>::ReverseIterator CurrentPosition = l.RBegin(); CurrentPosition != l.REnd(); CurrentPosition++)
	{
		cout << (*CurrentPosition)->Value << endl;
	}

	//vector<int> testVec;
	//list<int> testList;

	//for (int i = 0; i < 10; ++i)
	//{
	//	testVec.push_back(i);
	//	testList.push_back(i);
	//}
	//vector<int>::iterator v_iter;
	//list<int>::iterator l_iter;

	//for (vector<int>::reverse_iterator iter = testVec.rbegin(); iter != testVec.rend(); iter++)
	//{
	//	cout << (*iter) << endl;
	//}

	//for (list<int>::iterator iter = testList.begin(); iter != testList.end(); ++iter)
	//{
	//	cout << (*iter) << endl;
	//}

	//for (int i = 0; i < testVec.size(); ++i)
	//{
	//	cout << testVec[i] << endl;
	//}

	//for (int i = 0; i < testList.size(); ++i)
	//{
	//	cout << testVec[i] << endl;
	//}


	

 	return 0;
}