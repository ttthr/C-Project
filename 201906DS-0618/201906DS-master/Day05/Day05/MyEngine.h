#pragma once
#include "Engine.h"

class MyEngine : public Engine
{
public:
	MyEngine();
	virtual ~MyEngine();

	virtual bool Init() override;
	virtual bool Term() override;
	virtual bool Run() override;

protected:
	virtual void Input() override;
	virtual void Tick() override;
	virtual void Render() override;

};

