#include "DDALine.h"

DDALine::DDALine(Vector2 start, Vector2 end)
{
	this->start = start;
	this->end = end;
}


DDALine::~DDALine()
{
}

void DDALine::Draw(std::shared_ptr<Renderer> renderer)
{
	std::shared_ptr<Renderer2D> renderer2D = std::static_pointer_cast<Renderer2D>(renderer);

	int x0 = start.x, y0 = start.y;
	int x1 = end.x, y1 = end.y;

	int dx = x1 - x0;
	int dy = y1 - y0;
	float steps;
	
	if (dy > dx)
		steps = abs(dy);
	else
		steps = abs(dx);
	
	float xIncrement = dx / steps;
	float yIncrement = dy / steps;
	
	float x = x0;
	float y = y0;
	
	for (int i = 0; i < steps; i++)
	{
		renderer2D->DrawPoint(round(x), round(y));
	
		x += xIncrement;
		y += yIncrement;
	}
}
