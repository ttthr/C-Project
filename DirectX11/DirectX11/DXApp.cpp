#include "DXApp.h"

DXApp::DXApp(HINSTANCE hInstance)
{
	//扩档快 按眉 积己
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
