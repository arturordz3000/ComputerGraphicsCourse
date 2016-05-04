#include "GraphicEngine.h"

GraphicEngine::GraphicEngine()
{
	
}


GraphicEngine::~GraphicEngine()
{
	ClearComponents();
}

void GraphicEngine::AddComponent(shared_ptr<GraphicComponent> component)
{
	graphicComponents.push_back(component);
}

void GraphicEngine::ClearComponents()
{
	graphicComponents.clear();
}

void GraphicEngine::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	std::vector<shared_ptr<GraphicComponent>>::iterator componentsIterator = graphicComponents.begin();

	for (unsigned int i = 0; i < graphicComponents.size(); i++)
		componentsIterator[i]->Draw();

	glutSwapBuffers();
}

void GraphicEngine::InitializeViewport(WindowParameters windowParameters) {}

