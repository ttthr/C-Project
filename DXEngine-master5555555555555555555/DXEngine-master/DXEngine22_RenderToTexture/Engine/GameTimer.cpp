#include "GameTimer.h"



GameTimer::GameTimer()
{
}


GameTimer::~GameTimer()
{
}

void GameTimer::StartTimer()
{
	//값을 전달 받을 변수 선언
	LARGE_INTEGER frequencyCount;
	//하드웨어(CPU) 진동수 저장( 초단위 )
	QueryPerformanceFrequency(&frequencyCount);
	//64비트를 한번에 전달 해준다. (더블로 변환해서 저장해준다.)
	countsPerSecond = static_cast<double>(frequencyCount.QuadPart);
	//틱
	QueryPerformanceCounter(&frequencyCount);
	countStart = frequencyCount.QuadPart;

}

double GameTimer::GetTime() const
{
	//초 단위로 나눠서 시간을 얻어온다.
	LARGE_INTEGER currentTime;
	QueryPerformanceCounter(&currentTime);
	double time = static_cast<double>((currentTime.QuadPart - countStart) / countsPerSecond);
	
	return time;
}

float GameTimer::GetDeltaTime()
{
	//틱 단위 현재시간 구하기
	LARGE_INTEGER currentTime;
	QueryPerformanceCounter(&currentTime);
	//틱 카운트(간갹) 계산
	__int64 tickCount = currentTime.QuadPart - previousFrameTime;
	//이전 프레임 시간 갱신
	previousFrameTime = currentTime.QuadPart;

	//뺀시간이 0이면 0으로 만들어줌
	if (tickCount < 0)
	{
		tickCount = 0;
	}
	//프레임 시간을 초단위로 변환
	float deltaTime = static_cast<float>(tickCount / countsPerSecond);

	//뺀시간이 0이면 0으로 만들어줌
	if(deltaTime < 0.0f)
	{
		deltaTime = 0.0f;
	}

	return deltaTime;
}

void GameTimer::UpdateTimer(AppWindow * appWindow)
{
	//프레임 카운트 증가( 틱 단위 )
	++frameCount;
	//1초 지나면 타이머 초기화(원래는 여기서 하면 안되고 뺴야됨)
	if (GetTime() > 1.0f)
	{
		Reset(appWindow);
	}
}

void GameTimer::Reset(AppWindow * appWindow)
{
	fps = frameCount; //fps 기록
	frameCount = 0;   //카운트 초기화
	StartTimer();    //시작시간 다시돌리기
	
	//창 타이틀에 fps 문자열 추가
	TCHAR buffer[256];
	_itow_s(fps, buffer, 10);

	//visual studio 콘솔에 출력
	OutputDebugString(TEXT("FPS: "));
	OutputDebugString(buffer);
	OutputDebugString(TEXT("\n"));

	wstring newTiltle = wstring(appWindow->GetApplicationName());
	newTiltle = newTiltle + TEXT(" FPS:") + buffer;
	SetWindowText(appWindow->GetWindowHandle(), newTiltle.c_str());
}

int GameTimer::GetFPS() const
{
	return fps;
}

