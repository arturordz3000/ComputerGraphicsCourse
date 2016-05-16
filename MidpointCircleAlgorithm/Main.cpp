#include "..\CourseCore\Application.h"
#include "..\CourseCore\GraphicEngine2D.h"
#include "MidpointCircle.h"

shared_ptr<Application> application;
GraphicEngine2D graphicEngine;

MidpointCircle circle1 = MidpointCircle(Vector2(50, 50), 20);
MidpointCircle circle2 = MidpointCircle(Vector2(100, 150), 32);
MidpointCircle circle3 = MidpointCircle(Vector2(120, 100), 50);

int main(int argc, char **argv)
{
	application = Application::GetInstance("Midpoint circle algorithm");
	graphicEngine.AddComponent(make_shared<MidpointCircle>(circle1));
	graphicEngine.AddComponent(make_shared<MidpointCircle>(circle2));
	graphicEngine.AddComponent(make_shared<MidpointCircle>(circle3));
	application->SetGraphicEngine(make_shared<GraphicEngine2D>(graphicEngine));

	application->Run(&argc, argv);

	return 0;
}