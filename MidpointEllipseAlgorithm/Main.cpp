#include "..\CourseCore\Application.h"
#include "..\CourseCore\GraphicEngine2D.h"
#include "MidpointEllipse.h"

shared_ptr<Application> application;
GraphicEngine2D graphicEngine;

MidpointEllipse ellipse = MidpointEllipse(Vector2(100, 50), 80, 20);

int main(int argc, char **argv)
{
	application = Application::GetInstance("Midpoint Ellipse Algorithm");

	graphicEngine.AddComponent(make_shared<MidpointEllipse>(ellipse));
	application->SetGraphicEngine(make_shared<GraphicEngine2D>(graphicEngine));

	application->Run(&argc, argv);

	return 0;
}