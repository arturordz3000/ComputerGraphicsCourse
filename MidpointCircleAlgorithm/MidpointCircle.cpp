#include "MidpointCircle.h"


MidpointCircle::MidpointCircle(Vector2 center, int radius)
	: center(center), radius(radius)
{
}


MidpointCircle::~MidpointCircle()
{
}

void DrawPoint(int x, int y)
{
	glBegin(GL_POINTS);
	glColor3f(1, 1, 1);
	glVertex2i(x, y);
	glEnd();
}

void PlotCirclePoints(int x, int y, Vector2 center)
{
	DrawPoint(x + center.x, y + center.y);
	DrawPoint(x + center.x, -y + center.y);
	DrawPoint(y + center.x, x + center.y);
	DrawPoint(y + center.x, -x + center.y);

	DrawPoint(-x + center.x, y + center.y);
	DrawPoint(-x + center.x, -y + center.y);
	DrawPoint(-y + center.x, x + center.y);
	DrawPoint(-y + center.x, -x + center.y);
}

void MidpointCircle::Draw() 
{
	int p = 1 - radius;
	int x = 0;
	int y = radius;

	while (x <= y)
	{
		PlotCirclePoints(x, y, center);

		if (p >= 0)
		{
			p -= (y << 1) - 2;
			y--;
		}

		p += (x << 1) + 3;
		x++;
	}
}
