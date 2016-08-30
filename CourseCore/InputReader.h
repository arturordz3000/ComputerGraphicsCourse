#pragma once

#include "CoreStructures.h"

#ifdef COURSECORE_EXPORTS
#define COURSECORE_API __declspec(dllexport)
#else
#define COURSECORE_API __declspec(dllimport)
#endif

class COURSECORE_API InputReader
{
public:
	InputReader();
	~InputReader();

	virtual ButtonsState GetButtonsState(void *eventMessage) = 0;
};

#ifdef TARGET_WINDOWS
#include "WindowsInputReader.h"
#endif

