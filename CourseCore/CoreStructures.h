#pragma once

#ifdef COURSECORE_EXPORTS
#define COURSECORE_API __declspec(dllexport)
#else
#define COURSECORE_API __declspec(dllimport)
#endif

#include "Vector2.h"

struct COURSECORE_API WindowParameters
{
	int windowWidth;
	int windowHeight;
	Vector2 position;
};