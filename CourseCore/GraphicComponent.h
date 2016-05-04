#pragma once

#ifdef COURSECORE_EXPORTS
#define COURSECORE_API __declspec(dllexport)
#else
#define COURSECORE_API __declspec(dllimport)
#endif

#include <gl\glut.h>

class COURSECORE_API GraphicComponent
{
public:
	GraphicComponent();
	~GraphicComponent();

	virtual void Draw();
};

