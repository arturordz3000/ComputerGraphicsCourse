#pragma once
#include "GraphicEngine.h"
#include "Renderer2D.h"

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

