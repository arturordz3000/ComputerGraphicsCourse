#pragma once

#include "..\CourseCore\GraphicComponent.h"
#include "..\CourseCore\Vector2.h"

class MidpointCircle 
	: public GraphicComponent
{
public:
	Vector2 center;
	int radius;

	MidpointCircle(Vector2 center, int radius);
	~MidpointCircle();

	virtual void Draw();
};

