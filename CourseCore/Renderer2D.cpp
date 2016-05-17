#include "Renderer2D.h"


Renderer2D::Renderer2D()
{
}


Renderer2D::~Renderer2D()
{
}

void Renderer2D::DrawPoint(int x, int y)
{
	glBegin(GL_POINTS);
	glColor3f(1, 1, 1);
	glVertex2i(x, y);
	glEnd();
}

void Renderer2D::DrawPoint(int x, int y, Vector3 color)
{
	glBegin(GL_POINTS);
	glColor3f(color.x, color.y, color.z);
	glVertex2i(x, y);
	glEnd();
}
