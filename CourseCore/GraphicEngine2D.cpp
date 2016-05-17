#include "GraphicEngine2D.h"


GraphicEngine2D::GraphicEngine2D()
{
	renderer = make_shared<Renderer>(Renderer2D());
}


GraphicEngine2D::~GraphicEngine2D()
{
}

void GraphicEngine2D::InitializeViewport(WindowParameters windowParameters)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, windowParameters.windowWidth, 0.0, windowParameters.windowHeight);
	glMatrixMode(GL_MODELVIEW);
}
