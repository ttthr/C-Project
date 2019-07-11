#pragma once
#include <Windows.h>
#include "AppWindow.h"
#include "DXUtil.h"
using namespace std;
using namespace DirectX;

//����ð� - �����ð�

class GameTimer
{
public:
	GameTimer();
	~GameTimer();
private:
	double    countsPerSecond = 0.0; 	//CPU ������ ����
	__int64   countStart = 0;
	int       frameCount = 0; //������ ī��Ʈ ����
	int       fps = 0; //�ʴ� ������
	__int64   previousFrameTime = 0; //���� ������
public:
	void   StartTimer();
	double GetTime() const;
	float  GetDeltaTime();
	void   UpdateTimer(AppWindow* appWindow);
	void   Reset(AppWindow* appWindow);
	int    GetFPS() const;
};
