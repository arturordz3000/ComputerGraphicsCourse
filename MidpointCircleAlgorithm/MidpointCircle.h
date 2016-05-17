#pragma once

#include "..\CourseCore\GraphicComponent.h"
#include "..\CourseCore\Vector2.h"
#include "..\CourseCore\Renderer2D.h"
#include <memory>

class MidpointCircle 
	: public GraphicComponent
{
public:
	Vector2 center;
	int radius;

	MidpointCircle(Vector2 center, int radius);
	~MidpointCircle();

	virtual void Draw(std::shared_ptr<Renderer> renderer);

private:
	void PlotCirclePoints(std::shared_ptr<Renderer> renderer, int x, int y);
};

