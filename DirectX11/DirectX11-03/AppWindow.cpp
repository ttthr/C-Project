#include "AppWindow.h"
#include "Engine.h"

AppWindow* app = NULL;

//�޼��� ó����

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
			//�޼��� ť���� �޼����� �����´�.
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//�޼����� ���ٸ� ���ӷ����� ������.
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

	//â ����ü �� ����.
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = NULL; // NULL�� ������ �⺻ ���� ���õȴ�.
	wc.lpszClassName = TEXT("DXEngine"); 
	wc.lpfnWndProc = WindowProcessor;

	//Ŭ���� ���
	if (!RegisterClassEx(&wc))
	{
		cout << "Ŭ���� ��� ����" << endl;
		return false;
	}
	//�ڵ� ����

	hwnd = CreateWindow(wc.lpszClassName, applicationName, windowStyle, 0, 0,
		screenWidth, screenHeight, NULL, NULL, hInstance, NULL);

	// �ڵ� ���̸� ����
	if (hwnd == NULL)
	{
		cout << "�ڵ� ��� ���� ( �ڵ� NULL )" << endl;
		return false;
	}

	// â �����ֱ�
	ShowWindow(hwnd, SW_SHOW);

	return true;
}

LRESULT AppWindow::MessageProcessor(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//Űó�� �۾�
	switch (msg)
	{
	case WM_KEYDOWN:
	{
		if (wParam == VK_ESCAPE)
		{
			if (MessageBox(NULL, TEXT("���� �Ͻðڽ��ϱ�?"), TEXT("����"), (MB_YESNO | MB_ICONQUESTION) == IDYES))
			{
				DestroyWindow(this->hwnd); //��ư ������ 
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

	return DefWindowProc(hwnd, msg, wParam, lParam); //�⺻ ����

}
