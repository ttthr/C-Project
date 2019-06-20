#include <iostream>
#include <list>
#include <vector>
#include "LList.h"

using namespace std;

int main()
{
//	list<int> a;
//	a.find()

	LList l;
	for (int i = 0; i < 10; ++i)
	{
		l.PushBack(i);
	}

	l.InsertAfter(l.Find(3), 20);
	l.InsertAfter(l.Find(3), 30);
	l.InsertAfter(l.Find(3), 40);

	for (LList::Iterator CurrentPosition = l.Begin(); CurrentPosition != l.End(); CurrentPosition++)
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