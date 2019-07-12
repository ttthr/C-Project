#pragma once
#include <Windows.h>
#include "AppWindow.h"
#include "DXUtil.h"
using namespace std;
using namespace DirectX;

//현재시간 - 지난시간

class GameTimer
{
public:
	GameTimer();
	~GameTimer();
private:
	double    countsPerSecond = 0.0; 	//CPU 진동수 저장
	__int64   countStart = 0;
	int       frameCount = 0; //프레임 카운트 저장
	int       fps = 0; //초당 프레임
	__int64   previousFrameTime = 0; //이전 프레임
public:
	void   StartTimer();
	double GetTime() const;
	float  GetDeltaTime();
	void   UpdateTimer(AppWindow* appWindow);
	void   Reset(AppWindow* appWindow);
	int    GetFPS() const;
};
