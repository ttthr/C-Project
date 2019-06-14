#pragma once
class CEngine
{
public:
	CEngine();
	virtual~CEngine();
public:
	bool Init();
	bool Run();
	bool Term();
private:
	bool bIsRunning;
	int  input();
	void Tick();
	void Render();
	bool GameLoop();
};

