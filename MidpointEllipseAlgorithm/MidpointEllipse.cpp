#include "MidpointEllipse.h"


MidpointEllipse::MidpointEllipse(Vector2 center, int radiusX, int radiusY)
: center(center), radiusX(radiusX), radiusY(radiusY)
{
}


MidpointEllipse::~MidpointEllipse()
{
}

void PlotPoints(std::shared_ptr<Renderer2D> renderer2D, Vector2 center, int x, int y)
{
	renderer2D->DrawPoint(center.x + x, center.y + y);
	renderer2D->DrawPoint(center.x - x, center.y + y);
	renderer2D->DrawPoint(center.x + x, center.y - y);
	renderer2D->DrawPoint(center.x - x, center.y - y);
}

void MidpointEllipse::Draw(std::shared_ptr<Renderer> renderer)
{
	std::shared_ptr<Renderer2D> renderer2D = std::static_pointer_cast<Renderer2D>(renderer);

	int squareRadiusY = radiusY * radiusY;
	int squareRadiusX = radiusX * radiusX;
	int squareRadiusYTimes2 = squareRadiusY << 1;
	int squareRadiusXTimes2 = squareRadiusX << 1;

	/***
		Region 1
	***/

	int pX = 0;
	int pY = squareRadiusXTimes2 * radiusY;
	float p = squareRadiusY - (squareRadiusX * radiusY) + 0.25 * squareRadiusX;

	int x = 0;
	int y = radiusY;

	do
	{
		PlotPoints(renderer2D, center, x, y);

		if (p >= 0)
		{
			pY -= squareRadiusXTimes2;
			p -= pY;
			y--;
		}

		x++;

		pX += squareRadiusYTimes2;
		p += pX + squareRadiusY;

	} while (pX < pY);

	/***
	Region 2
	***/

	float lastXPlusHalf = x + 0.5f;
	int lastYMinusOne = y - 1;

	p = squareRadiusY * (lastXPlusHalf * lastXPlusHalf) + 
		squareRadiusX * (lastYMinusOne * lastYMinusOne) -
		squareRadiusX * squareRadiusY;

	do
	{
		PlotPoints(renderer2D, center, x, y);

		if (p <= 0)
		{
			pX += squareRadiusYTimes2;
			p += pX;
			x++;
		}

		y--;

		pY -= squareRadiusXTimes2;
		p -= pY;

	} while (y >= 0);
}
