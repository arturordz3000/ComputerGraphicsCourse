#pragma once

#ifdef COURSECORE_EXPORTS
#define COURSECORE_API __declspec(dllexport)
#else
#define COURSECORE_API __declspec(dllimport)
#endif

#include "CoreStructures.h"
#include "InputReader.h"
#include <memory>

class COURSECORE_API Input
{
private:
	static std::shared_ptr<Input> input;

	ButtonsState buttonsDown;
	ButtonsState buttonsUp;
	std::shared_ptr<InputReader> inputReader;

public:

	Input(std::shared_ptr<InputReader> inputReader);
	~Input();

	static std::shared_ptr<Input> GetInstance();

	bool HandleInput(void* eventMessage);
	void Reset();

	bool IsButtonDown(Button button);
	bool IsButtonUp(Button button);
};

