#include "..\CourseCore\Application.h"
#include "..\CourseCore\GraphicEngine2D.h"
#include "BresenhamLine.h"

shared_ptr<Application> application;
GraphicEngine2D graphicEngine;

/***
	Positive slopes lesser than 1
***/
BresenhamLine line = BresenhamLine(Vector2(0, 0), Vector2(300, 200));
BresenhamLine line2 = BresenhamLine(Vector2(200, 100), Vector2(0, 0), Vector3(0, 1, 0));

/***
	Negative slopes lesser than 1
***/
BresenhamLine line3 = BresenhamLine(Vector2(0, 250), Vector2(300, 0), Vector3(1, 0, 0));
BresenhamLine line4 = BresenhamLine(Vector2(300, 0), Vector2(100, 50), Vector3(0, 1, 1));

/***
	Positive slopes greater than 1
***/
BresenhamLine line5 = BresenhamLine(Vector2(0, 0), Vector2(200, 300), Vector3(1, 1, 0));
BresenhamLine line6 = BresenhamLine(Vector2(100, 200), Vector2(0, 0), Vector3(1, 0, 1));

/***
	Negative slopes greater than 1
***/
BresenhamLine line7 = BresenhamLine(Vector2(250, 0), Vector2(0, 300), Vector3(1, 0.5f, 0.25f));
BresenhamLine line8 = BresenhamLine(Vector2(0, 300), Vector2(50, 100), Vector3(0.25f, 0.5f, 1));

int main(int argc, char **argv)
{
	application = Application::GetInstance("Bresenham Line Algorithm");

	graphicEngine.AddComponent(make_shared<BresenhamLine>(line));
	graphicEngine.AddComponent(make_shared<BresenhamLine>(line2));
	graphicEngine.AddComponent(make_shared<BresenhamLine>(line3));
	graphicEngine.AddComponent(make_shared<BresenhamLine>(line4));
	graphicEngine.AddComponent(make_shared<BresenhamLine>(line5));
	graphicEngine.AddComponent(make_shared<BresenhamLine>(line6));
	graphicEngine.AddComponent(make_shared<BresenhamLine>(line7));
	graphicEngine.AddComponent(make_shared<BresenhamLine>(line8));

	application->SetGraphicEngine(make_shared<GraphicEngine2D>(graphicEngine));

	application->Run(&argc, argv);

	return 0;
}