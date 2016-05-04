#pragma once

#ifdef COURSECORE_EXPORTS
#define COURSECORE_API __declspec(dllexport)
#else
#define COURSECORE_API __declspec(dllimport)
#endif

#include "GraphicEngine.h"
#include "Vector2.h"
#include "CoreStructures.h"

class COURSECORE_API Application
{
private:
	WindowParameters windowParameters;
	shared_ptr<GraphicEngine> graphicEngine;

	WindowParameters GetWindowDefaultParameters();

	static void MainLoop();

public:
	Application();
	~Application();

	void SetWindowParameters(WindowParameters windowParameters);
	void SetWindowParameters(int width, int height, Vector2 position);
	WindowParameters GetWindowParameters();

	void SetGraphicEngine(shared_ptr<GraphicEngine> graphicEngine);

	void Run(int *argc, char **argv);

	static shared_ptr<Application> GetInstance();
};

