#pragma once

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

namespace Memory
{
	template <class T> void SafeRelease(T& t)
	{
		if (t)
		{
			t->Release();
			t = NULL;
		}
	}

	template <class T> void SafeDelete(T& t)
	{
		if (t)
		{
			delete t;
			t = NULL;
		}
	}

	// �迭 �޸� ������.
	template <class T> void SafeDeleteArray(T& t)
	{
		if (t)
		{
			delete[] t;
			t = NULL;
		}
	}
}
// C4316 ��� �ذ��
// 16����Ʈ ������ ���� ������ �����ε� Ŭ����
template<size_t T>
class AlinedAllocation
{
public:
	static void* operator new(size_t byteSize)
	{
		return _aligned_malloc(byteSize, T);
	}
	static void operator delete(void* Pointer)
	{
		_aligned_free(Pointer);
	}

};
// ���� Ȯ�ο� �Լ�.
bool IsError(HRESULT hr, LPCTSTR msg);