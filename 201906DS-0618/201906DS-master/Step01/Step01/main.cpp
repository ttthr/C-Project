#include <stdio.h>
#include "Engine.h"
#include "Player.h"

int main()
{
	Engine* engine = new Engine();
	
	engine->Run();

	delete engine;
	engine = nullptr;

	return 0;
}