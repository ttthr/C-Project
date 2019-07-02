#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;
class Engine;

class AppWindow
{
public:
	AppWindow(HINSTANCE hInstance);
	~AppWindow();
protected:
	HWND hwnd; //������ �ڵ�
	HINSTANCE hInstance; //â �ν��Ͻ�
	UINT screenWidth; //����
	UINT screenHeight; //����
	LPCTSTR applicationName;  //â �̸�
	DWORD windowStyle; //â ��Ÿ�� �� (���)
public:
	int Run(Engine* Engine);
	bool InitWindow();
	virtual LRESULT MessageProcessor(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

};

