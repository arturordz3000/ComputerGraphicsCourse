#include "..\CourseCore\Application.h"
#include "..\CourseCore\GraphicEngine2D.h"

shared_ptr<Application> application;
GraphicEngine2D graphicEngine;

int main(int argc, char **argv)
{
	application = Application::GetInstance("New Project");

	application->SetGraphicEngine(make_shared<GraphicEngine2D>(graphicEngine));

	application->Run(&argc, argv);

	return 0;
}