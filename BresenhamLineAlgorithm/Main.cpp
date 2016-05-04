#include "..\CourseCore\Application.h"
#include "..\CourseCore\GraphicEngine2D.h"
#include "BresenhamLine.h"

shared_ptr<Application> application;
GraphicEngine2D graphicEngine;

/***
	Positive Slopes
***/
BresenhamLine line = BresenhamLine(Vector2(0, 0), Vector2(300, 200));
BresenhamLine line2 = BresenhamLine(Vector2(200, 100), Vector2(0, 0), Vector3(0, 1, 0));

/***
Negative Slopes
***/
BresenhamLine line3 = BresenhamLine(Vector2(0, 250), Vector2(300, 0), Vector3(1, 0, 0));
BresenhamLine line4 = BresenhamLine(Vector2(300, 0), Vector2(100, 50), Vector3(0, 1, 1));

int main(int argc, char **argv)
{
	application = Application::GetInstance("Bresenham Line Algorithm");
	graphicEngine.AddComponent(make_shared<BresenhamLine>(line));
	graphicEngine.AddComponent(make_shared<BresenhamLine>(line2));
	graphicEngine.AddComponent(make_shared<BresenhamLine>(line3));
	graphicEngine.AddComponent(make_shared<BresenhamLine>(line4));
	application->SetGraphicEngine(make_shared<GraphicEngine2D>(graphicEngine));

	application->Run(&argc, argv);

	return 0;
}