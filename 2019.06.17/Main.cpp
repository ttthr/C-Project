#include<iostream>
#include<vector>

using namespace std;

#include "CMyVector.h"

//2019.06.17 
//STL


int main()
{
	
	CMyVector<int> pVec;

	for(size_t i =0 ; i < 10; ++i)
		pVec.PushBack(i);

	cout << "����� ��" << endl;
	for (size_t i = 0; i < pVec.GetPosition(); ++i)
		cout << pVec[i] << ",";

	//pVec.Erase(pVec[5]);
	pVec.Erase(1);

	cout << endl;

	cout << "���� �� " << endl;
	for (size_t i = 0; i < pVec.GetPosition(); ++i)
		cout << pVec[i] << ",";

	//cout << endl;
	//cout << "�� �ֱ�" << endl;

	//pVec.Insert(pVec[5]);
	//for (size_t i = 0; i < pVec.GetPosition(); ++i)
	//	cout << pVec[i] << ",";

	/*vector<int> v;
	v.push_back(1);
	v.push_back(2);
*/
	//cout << "����� ��" << endl;

	//for (int i = 0; i < v.size(); ++i)
	//	cout  << v[i];

	//cout << endl;
	//v.erase(v.begin(), v.end() -1 );

	//cout << "���� ��" << endl;

	//for (int i = 0; i < v.size(); ++i)
	//	cout << v[i];
	//


	return 0;
}