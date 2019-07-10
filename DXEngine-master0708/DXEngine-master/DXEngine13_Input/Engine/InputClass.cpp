#include "InputClass.h"



InputClass::InputClass()
{
	keyboard = new Keyboard();
	mouse = new Mouse();

}

InputClass::~InputClass()
{
	Memory::SafeDelete(keyboard);
	Memory::SafeDelete(mouse);
}

bool InputClass::InitializeInput(HWND hwnd)
{
	mouse->SetWindow(hwnd);
	mouse->SetMode(Mouse::Mode::MODE_RELATIVE);
	return true;
}

bool InputClass::IsKeyDown(Keyboard::Keys key)
{
	return keyboard->GetState().IsKeyDown(key);
	
}

bool InputClass::IsKeyUp(Keyboard::Keys key)
{
	return keyboard->GetState().IsKeyUp(key);
}

void InputClass::ResetKeyBoardState()
{
	keyboard->Reset();
}

XMFLOAT2 InputClass::GetMouseDragState()
{
	Mouse::State state = mouse->GetState();
	return XMFLOAT2(state.x , state.y);
}
