#include "AppWindow.h"
#include "Engine.h"

AppWindow* app = NULL;

//메세지 처리자

LRESULT CALLBACK WindowProcessor(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParm)
{
	if (app != NULL)
	{
		return app->MessageProcessor(hwnd, msg, wParam, lParm);

	}
	else
	{
		return DefWindowProc(hwnd, msg, wParam, lParm);
	}

}

AppWindow::AppWindow(HINSTANCE hInstance)
{
	hwnd = NULL;
	this->hInstance = hInstance;
	screenWidth = 800;
	screenHeight = 600;
	applicationName = TEXT("Egine00 - Window SetUp");
	windowStyle = WS_OVERLAPPEDWINDOW;
	app = this;



}
AppWindow::~AppWindow()
{



}
int AppWindow::Run(Engine * Engine)
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0 , 0 , PM_REMOVE))
		{
			//메세지 큐에서 메세지를 가져온다.
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//메세지가 없다면 게임루프를 돌린다.
			Engine->Update();
			Engine->Render();
			
		}

	}

	return 0;
}

bool AppWindow::InitWindow()
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	//창 구조체 값 설정.
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = NULL; // NULL을 넣으면 기본 값이 셋팅된다.
	wc.lpszClassName = TEXT("DXEngine"); 
	wc.lpfnWndProc = WindowProcessor;

	//클래스 등록
	if (!RegisterClassEx(&wc))
	{
		cout << "클래스 등록 실패" << endl;
		return false;
	}
	//핸들 설정

	hwnd = CreateWindow(wc.lpszClassName, applicationName, windowStyle, 0, 0,
		screenWidth, screenHeight, NULL, NULL, hInstance, NULL);

	// 핸들 널이면 ㅂㅂ
	if (hwnd == NULL)
	{
		cout << "핸들 등록 실패 ( 핸들 NULL )" << endl;
		return false;
	}

	// 창 보여주기
	ShowWindow(hwnd, SW_SHOW);

	return true;
}

LRESULT AppWindow::MessageProcessor(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//키처리 작업
	switch (msg)
	{
	case WM_KEYDOWN:
	{
		if (wParam == VK_ESCAPE)
		{
			if (MessageBox(NULL, TEXT("종료 하시겠습니까?"), TEXT("종료"), (MB_YESNO | MB_ICONQUESTION) == IDYES))
			{
				DestroyWindow(this->hwnd); //버튼 눌리면 
			}
		}

	}
	return 0;
	case WM_DESTROY:
	{
		PostQuitMessage(0);
	}
	return 0;
	default:
		break;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam); //기본 동작

}
