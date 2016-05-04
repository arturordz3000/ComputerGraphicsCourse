#pragma once

#include "..\CourseCore\GraphicComponent.h"
#include "..\CourseCore\Vector2.h"
#include "..\CourseCore\Vector3.h"
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

	virtual void Draw();

private:
	void DrawPoint(int x, int y);
	void DrawLineWithSlopeLesserThan1(Vector2 start, Vector2 end, int dx, int dy, int yIncrement = 1);
	void DrawLineWithSlopeGreaterThan1(Vector2 start, Vector2 end, int dx, int dy, int xIncrement = 1);
};

