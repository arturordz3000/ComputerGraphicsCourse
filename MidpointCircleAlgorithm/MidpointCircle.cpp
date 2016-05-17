#include "MidpointCircle.h"


MidpointCircle::MidpointCircle(Vector2 center, int radius)
	: center(center), radius(radius)
{
}


MidpointCircle::~MidpointCircle()
{
}

void MidpointCircle::PlotCirclePoints(std::shared_ptr<Renderer> renderer, int x, int y)
{
	std::shared_ptr<Renderer2D> renderer2D = std::static_pointer_cast<Renderer2D>(renderer);

	renderer2D->DrawPoint(x + center.x, y + center.y);
	renderer2D->DrawPoint(x + center.x, -y + center.y);
	renderer2D->DrawPoint(y + center.x, x + center.y);
	renderer2D->DrawPoint(y + center.x, -x + center.y);

	renderer2D->DrawPoint(-x + center.x, y + center.y);
	renderer2D->DrawPoint(-x + center.x, -y + center.y);
	renderer2D->DrawPoint(-y + center.x, x + center.y);
	renderer2D->DrawPoint(-y + center.x, -x + center.y);
}

void MidpointCircle::Draw(std::shared_ptr<Renderer> renderer)
{
	int p = 1 - radius;
	int x = 0;
	int y = radius;

	while (x <= y)
	{
		PlotCirclePoints(renderer, x, y);

		if (p >= 0)
		{
			p -= (y << 1) - 2;
			y--;
		}

		p += (x << 1) + 3;
		x++;
	}
}
