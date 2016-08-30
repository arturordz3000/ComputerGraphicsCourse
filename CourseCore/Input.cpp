#include "Input.h"

std::shared_ptr<Input> Input::input = nullptr;

Input::Input(std::shared_ptr<InputReader> inputReader)
{
	this->inputReader = inputReader;
}


Input::~Input()
{
}

std::shared_ptr<Input> BuildInputInstance()
{
#ifdef TARGET_WINDOWS
	std::shared_ptr<WindowsInputReader> inputReader = std::make_shared<WindowsInputReader>(WindowsInputReader());
#endif

	return std::make_shared<Input>(Input(inputReader));
}

std::shared_ptr<Input> Input::GetInstance()
{
	if (Input::input == nullptr)
		Input::input = BuildInputInstance();

	return Input::input;
}

bool Input::HandleInput(void* eventMessage)
{
	ButtonsState currentButtonsState = inputReader->GetButtonsState(eventMessage);

	if (currentButtonsState == INPUT_NOT_HANDLED)
		return false;

	// TODO: Check for button downs and ups!

	return true;
}
