#include<iostream>
using namespace std;
#include "CEngine.h"


int main()
{
	CEngine* pEngine = new CEngine;

	pEngine->Run();

	if (pEngine != nullptr)
	{
		delete pEngine;
		pEngine = nullptr;
	}
	return 0;

}