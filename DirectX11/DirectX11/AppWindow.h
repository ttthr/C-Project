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
	HWND hwnd; //윈도우 핸들
	HINSTANCE hInstance; //창 인스턴스
	UINT screenWidth; //가로
	UINT screenHeight; //세로
	LPCTSTR applicationName;  //창 이름
	DWORD windowStyle; //창 스타일 값 (모양)
public:
	int Run(Engine* Engine);
	bool InitWindow();
	virtual LRESULT MessageProcessor(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

};

