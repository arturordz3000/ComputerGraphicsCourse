#pragma once

#include "..\CourseCore\GraphicComponent.h"
#include "..\CourseCore\Vector2.h"
#include <math.h>

class DDALine :
	public GraphicComponent
{
public:
	Vector2 start;
	Vector2 end;

	DDALine(Vector2 start, Vector2 end);
	~DDALine();

	virtual void Draw();
};

