#pragma once
#include "AppWindow.h"

class DXApp
{
public:
	DXApp(HINSTANCE hInstance);
	virtual ~DXApp();
protected:
	AppWindow* window;
public:
	virtual int Run() = 0;
	virtual bool Init();
	virtual void Update() = 0;
	virtual void Render() = 0;
};

