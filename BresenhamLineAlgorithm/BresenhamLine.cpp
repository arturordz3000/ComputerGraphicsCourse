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

void BresenhamLine::DrawLineWithSlopeGreaterThan1(Vector2 start, Vector2 end, int dx, int dy, int xIncrement)
{
	int error = 0;
	int x = start.x;

	for (int y = start.y; y <= end.y; y++)
	{
		DrawPoint(x, y);
		error += dx;

		// error << 1 is equals to 2 * error
		if ((error << 1) >= dy)
		{
			x += xIncrement;
			error -= dy;
		}
	}
}

void BresenhamLine::Draw()
{
	int dx = end.x - start.x;
	int dy = end.y - start.y;

	if (abs(dx) > abs(dy))
	{
		if (start.x > end.x)
		{
			Vector2 tempStart = start;
			start = end;
			end = tempStart;

			dx = -dx;
			dy = -dy;
		}

		if (dy > 0)
			DrawLineWithSlopeLesserThan1(start, end, dx, dy, 1);
		else
			DrawLineWithSlopeLesserThan1(start, end, dx, -dy, -1);
	}
	else
	{
		if (start.y > end.y)
		{
			Vector2 tempStart = start;
			start = end;
			end = tempStart;

			dx = -dx;
			dy = -dy;
		}

		if (dx > 0)
			DrawLineWithSlopeGreaterThan1(start, end, dx, dy, 1);
		else
			DrawLineWithSlopeGreaterThan1(start, end, -dx, dy, -1);

	}
}
