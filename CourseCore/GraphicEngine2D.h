#pragma once
#include "GraphicEngine.h"
#include <Windows.h>
#include <gl\glut.h>

#ifdef COURSECORE_EXPORTS
#define COURSECORE_API __declspec(dllexport)
#else
#define COURSECORE_API __declspec(dllimport)
#endif

class COURSECORE_API GraphicEngine2D :
	public GraphicEngine
{
public:
	GraphicEngine2D();
	~GraphicEngine2D();

	virtual void InitializeViewport(WindowParameters windowParameters);
};

