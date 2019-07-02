#include "Engine.h"


Engine::Engine(HINSTANCE hInstance)
	:DXApp(hInstance)
{


}

Engine::~Engine()
{
}

int Engine::Run()
{
	//엔진 루프
	return window->Run(this);
}

bool Engine::Init()
{
	if (DXApp::Init() == false)
	{
		return false;
	}
	return true;
}

void Engine::Update()
{
}

void Engine::Render()
{

}
