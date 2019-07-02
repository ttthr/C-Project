#pragma once

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dcompiler.lib")

bool ISError(HRESULT hr, LPCTSTR msg);

//namespace Memory
//{
//	template<typename T> SafeRelease(T& t)
//	{
//		if (t)
//		{
//			t->Release();
//			t = NULL;
//		}
//	}
//	template<typename T> SafeDelete(T& t)
//	{
//		if (t)
//		{
//			delete t;
//			t = NULL;
//		}
//	}
//	template<typename T> void SafeDeleteArray(T& t)
//	{
//		if (t)
//		{
//			delete[] t;
//			t = NULL;
//		}
//	}
//}
//
