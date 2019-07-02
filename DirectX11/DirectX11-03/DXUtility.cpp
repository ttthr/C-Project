#include "DXUtility.h"

bool ISError(HRESULT hr, LPCTSTR msg)
{
	if (hr < 0)
	{
		MessageBox(NULL, msg, TEXT("¿À·ù"), MB_OK);
		return true;
	}
	return false;
}
