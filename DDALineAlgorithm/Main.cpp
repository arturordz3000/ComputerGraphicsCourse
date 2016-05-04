#include "..\CourseCore\Application.h"
#include "..\CourseCore\GraphicEngine2D.h"
#include "DDALine.h"

shared_ptr<Application> application;
GraphicEngine2D graphicEngine;
DDALine line = DDALine(Vector2(0, 0), Vector2(300, 200));

int main(int argc, char **argv)
{
	application = Application::GetInstance();
	graphicEngine.AddComponent(make_shared<DDALine>(line));
	application->SetGraphicEngine(make_shared<GraphicEngine2D>(graphicEngine));

	application->Run(&argc, argv);

	return 0;
}