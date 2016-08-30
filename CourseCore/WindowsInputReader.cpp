#include "WindowsInputReader.h"


WindowsInputReader::WindowsInputReader()
{
}


WindowsInputReader::~WindowsInputReader()
{
}

bool IsMouseInput(UINT message)
{

}

bool IsKeyboardInput(UINT message)
{

}

ButtonsState WindowsInputReader::GetButtonsState(void *eventMessage)
{
	MSG msg = *((MSG*)eventMessage);

	if (IsMouseInput(msg.message))
		int i = 0;
	else if (IsKeyboardInput(msg.message))
		int i = 0;

	return INPUT_NOT_HANDLED;
}
