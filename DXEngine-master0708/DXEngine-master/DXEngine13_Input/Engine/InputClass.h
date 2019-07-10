#pragma once

#include "DXUtil.h"
#include "../Library/Keyboard.h"
#include "../Library/Mouse.h"

#pragma comment(lib, "Library/DirectXTK.lib")

using namespace DirectX;

class InputClass
{
public:
	InputClass();
	~InputClass();
private:
	Keyboard* keyboard;
	Mouse*  mouse;
public:
	bool InitializeInput(HWND hwnd);
	bool IsKeyDown(Keyboard::Keys key);
	bool IsKeyUp(Keyboard::Keys key);
	void ResetKeyBoardState();
	XMFLOAT2 GetMouseDragState();

};

