#pragma once

#include "..\CourseCore\GraphicComponent.h"
#include "..\CourseCore\Vector2.h"
#include "..\CourseCore\Vector3.h"
#include "..\CourseCore\Renderer2D.h"
#include <math.h>

class BresenhamLine :
	public GraphicComponent
{
public:
	Vector2 start;
	Vector2 end;
	Vector3 color;

	BresenhamLine(Vector2 start, Vector2 end);
	BresenhamLine(Vector2 start, Vector2 end, Vector3 color);
	~BresenhamLine();

	virtual void Draw(std::shared_ptr<Renderer> renderer);

private:
	void DrawLineWithSlopeLesserThan1(std::shared_ptr<Renderer> renderer, Vector2 start, Vector2 end, int dx, int dy, int yIncrement = 1);
	void DrawLineWithSlopeGreaterThan1(std::shared_ptr<Renderer> renderer, Vector2 start, Vector2 end, int dx, int dy, int xIncrement = 1);
};

