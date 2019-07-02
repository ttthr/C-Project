#include "DXApp.h"

DXApp::DXApp(HINSTANCE hInstance)
{
	//윈도우 객체 생성
	window = new AppWindow(hInstance);

}
DXApp::~DXApp()
{
	if (window != NULL)
	{
		delete window;
	}

}
bool DXApp::Init()
{
	if (window->InitWindow() == false)
	{
		return false;
	}

	return true;
}
