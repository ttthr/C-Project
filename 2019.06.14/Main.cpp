#include "Define.h"
#include "CEngine.h"
#include "CMyEngine.h"


int main()
{
	CEngine* pMyEngine = new CMyEngine;

	pMyEngine->Run();


	if (pMyEngine != nullptr)
	{
		delete pMyEngine;
		pMyEngine = nullptr;
	}
	return 0;

}