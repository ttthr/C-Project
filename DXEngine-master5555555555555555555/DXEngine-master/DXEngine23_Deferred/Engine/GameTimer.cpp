#include "GameTimer.h"



GameTimer::GameTimer()
{
}


GameTimer::~GameTimer()
{
}

void GameTimer::StartTimer()
{
	//���� ���� ���� ���� ����
	LARGE_INTEGER frequencyCount;
	//�ϵ����(CPU) ������ ����( �ʴ��� )
	QueryPerformanceFrequency(&frequencyCount);
	//64��Ʈ�� �ѹ��� ���� ���ش�. (����� ��ȯ�ؼ� �������ش�.)
	countsPerSecond = static_cast<double>(frequencyCount.QuadPart);
	//ƽ
	QueryPerformanceCounter(&frequencyCount);
	countStart = frequencyCount.QuadPart;

}

double GameTimer::GetTime() const
{
	//�� ������ ������ �ð��� ���´�.
	LARGE_INTEGER currentTime;
	QueryPerformanceCounter(&currentTime);
	double time = static_cast<double>((currentTime.QuadPart - countStart) / countsPerSecond);
	
	return time;
}

float GameTimer::GetDeltaTime()
{
	//ƽ ���� ����ð� ���ϱ�
	LARGE_INTEGER currentTime;
	QueryPerformanceCounter(&currentTime);
	//ƽ ī��Ʈ(����) ���
	__int64 tickCount = currentTime.QuadPart - previousFrameTime;
	//���� ������ �ð� ����
	previousFrameTime = currentTime.QuadPart;

	//���ð��� 0�̸� 0���� �������
	if (tickCount < 0)
	{
		tickCount = 0;
	}
	//������ �ð��� �ʴ����� ��ȯ
	float deltaTime = static_cast<float>(tickCount / countsPerSecond);

	//���ð��� 0�̸� 0���� �������
	if(deltaTime < 0.0f)
	{
		deltaTime = 0.0f;
	}

	return deltaTime;
}

void GameTimer::UpdateTimer(AppWindow * appWindow)
{
	//������ ī��Ʈ ����( ƽ ���� )
	++frameCount;
	//1�� ������ Ÿ�̸� �ʱ�ȭ(������ ���⼭ �ϸ� �ȵǰ� ���ߵ�)
	if (GetTime() > 1.0f)
	{
		Reset(appWindow);
	}
}

void GameTimer::Reset(AppWindow * appWindow)
{
	fps = frameCount; //fps ���
	frameCount = 0;   //ī��Ʈ �ʱ�ȭ
	StartTimer();    //���۽ð� �ٽõ�����
	
	//â Ÿ��Ʋ�� fps ���ڿ� �߰�
	TCHAR buffer[256];
	_itow_s(fps, buffer, 10);

	//visual studio �ֿܼ� ���
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

