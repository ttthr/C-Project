#include "DXUtil.h"

bool IsError(HRESULT hr, LPCTSTR msg)
{
	// ���� ������ ���� �޽��� �����ִ� �޽��� â ����.
	if (hr < 0)
	{
		MessageBox(NULL, msg, TEXT("����"), MB_OK);
		return true;
	}

	return false;
}

wstring ConcatString(LPCTSTR & target, LPCTSTR source)
{
	wstring concatString(target);
	concatString = concatString + source;

	return concatString;
}
