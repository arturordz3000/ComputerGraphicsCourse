#include "BresenhamLine.h"


BresenhamLine::BresenhamLine(Vector2 start, Vector2 end)
{
	this->start = start;
	this->end = end;
	color = Vector3(1, 1, 1);
}

BresenhamLine::BresenhamLine(Vector2 start, Vector2 end, Vector3 color)
{
	this->color = color;
	this->start = start;
	this->end = end;
}


BresenhamLine::~BresenhamLine()
{
}

void BresenhamLine::DrawPoint(int x, int y)
{
	glBegin(GL_POINTS);
	glColor3f(color.x, color.y, color.z);
	glVertex2i(x, y);
	glEnd();
}

void BresenhamLine::DrawLineWithSlopeLesserThan1(Vector2 start, Vector2 end, int dx, int dy, int yIncrement)
{
	int error = 0;
	int y = start.y;

	for (int x = start.x; x <= end.x; x++)
	{
		DrawPoint(x, y);
		error += dy;

		// error << 1 is equals to 2 * error
		if ((error << 1) >= dx)
		{
			y += yIncrement;
			error -= dx;
		}
	}
}

void BresenhamLine::Draw()
{
	Vector2 lineStart;
	Vector2 lineEnd;

	if (start.x > end.x)
	{
		lineStart = end;
		lineEnd = start;
	}
	else
	{
		lineStart = start;
		lineEnd = end;
	}

	int dx = lineEnd.x - lineStart.x;
	int dy = lineEnd.y - lineStart.y;

	if (abs(dx) > abs(dy))
	{
		if (dy > 0)
			DrawLineWithSlopeLesserThan1(lineStart, lineEnd, dx, dy, 1);
		else
			DrawLineWithSlopeLesserThan1(lineStart, lineEnd, dx, -dy, -1);
	}
}
