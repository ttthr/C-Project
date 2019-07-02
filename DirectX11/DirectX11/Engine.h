#pragma once
#include "DXApp.h"

class Engine :
	public DXApp
{
public:
	Engine(HINSTANCE hInstance);
	virtual ~Engine();
public:
	virtual int Run()override;;
	virtual bool Init()override;
	virtual void Update() override;
	virtual void Render()override;

};

