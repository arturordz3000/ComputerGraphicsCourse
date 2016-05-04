#pragma once

#ifdef COURSECORE_EXPORTS
#define COURSECORE_API __declspec(dllexport)
#else
#define COURSECORE_API __declspec(dllimport)
#endif

#include <Windows.h>
#include <gl\glut.h>
#include <vector>
#include <memory>
#include "GraphicComponent.h"
#include "CoreStructures.h"

using namespace std;

class COURSECORE_API GraphicEngine
{
private:
	vector<shared_ptr<GraphicComponent>> graphicComponents;

public:
	GraphicEngine();
	~GraphicEngine();

	void AddComponent(shared_ptr<GraphicComponent> component);
	void ClearComponents();
	void Draw();
	virtual void InitializeViewport(WindowParameters windowParameters);
};

