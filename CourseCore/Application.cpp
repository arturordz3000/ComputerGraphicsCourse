#include "Application.h"

static shared_ptr<Application> instance;

Application::Application()
{
	windowParameters = GetWindowDefaultParameters();
}

Application::Application(std::string title)
{
	windowParameters = GetWindowDefaultParameters();
	this->title = title;
}

Application::~Application()
{
	
}

WindowParameters Application::GetWindowDefaultParameters()
{
	WindowParameters windowParameters;
	windowParameters.position.x = windowParameters.position.y = 100;
	windowParameters.windowWidth = windowParameters.windowHeight = 320;

	return windowParameters;
}

void Application::SetWindowParameters(WindowParameters windowParameters)
{
	this->windowParameters = windowParameters;
}

void Application::SetWindowParameters(int width, int height, Vector2 position)
{
	this->windowParameters.windowWidth = width;
	this->windowParameters.windowHeight = width;
	this->windowParameters.position = position;
}

WindowParameters Application::GetWindowParameters()
{
	return this->windowParameters;
}

void Application::SetGraphicEngine(shared_ptr<GraphicEngine> graphicEngine)
{
	this->graphicEngine = graphicEngine;
}

void Application::Run(int *argc, char **argv)
{
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(windowParameters.position.x, windowParameters.position.y);
	glutInitWindowSize(windowParameters.windowWidth, windowParameters.windowHeight);

	if (title.empty())
		glutCreateWindow("Unnamed Application");
	else
		glutCreateWindow(title.c_str());

	graphicEngine->InitializeViewport(windowParameters);

	glutDisplayFunc(this->MainLoop);
	glutMainLoop();
}

void Application::MainLoop()
{
	shared_ptr<GraphicEngine> graphicEngine = Application::GetInstance()->graphicEngine;

	if (graphicEngine != nullptr)
		graphicEngine->Draw();
}

shared_ptr<Application> Application::GetInstance(std::string title)
{
	if (instance == nullptr)
	{
		Application newApplication(title);
		instance = make_shared<Application>(newApplication);
	}

	return instance;
}
