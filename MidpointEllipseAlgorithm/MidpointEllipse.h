#pragma once

#include "..\CourseCore\GraphicComponent.h"
#include "..\CourseCore\Vector2.h"
#include "..\CourseCore\Vector3.h"
#include "..\CourseCore\Renderer2D.h"
#include <math.h>

class MidpointEllipse :
	public GraphicComponent
{
private:
	Vector2 center;
	int radiusX;
	int radiusY;

public:
	MidpointEllipse(Vector2 center, int radiusX, int radiusY);
	~MidpointEllipse();

	virtual void Draw(std::shared_ptr<Renderer> renderer);
};

