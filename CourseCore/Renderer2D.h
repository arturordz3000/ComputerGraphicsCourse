#pragma once

#include "Vector3.h"
#include "Renderer.h"
#include <gl\glut.h>

#ifdef COURSECORE_EXPORTS
#define COURSECORE_API __declspec(dllexport)
#else
#define COURSECORE_API __declspec(dllimport)
#endif

class COURSECORE_API Renderer2D
	: public Renderer
{
public:
	Renderer2D();
	~Renderer2D();

	void DrawPoint(int x, int y);
	void DrawPoint(int x, int y, Vector3 color);
};

