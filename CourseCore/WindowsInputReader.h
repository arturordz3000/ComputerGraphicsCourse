#pragma once

#include "InputReader.h"
#include <Windows.h>

#ifdef COURSECORE_EXPORTS
#define COURSECORE_API __declspec(dllexport)
#else
#define COURSECORE_API __declspec(dllimport)
#endif


class COURSECORE_API WindowsInputReader :
	public InputReader
{
public:
	WindowsInputReader();
	~WindowsInputReader();

	virtual ButtonsState GetButtonsState(void *eventMessage);
};

