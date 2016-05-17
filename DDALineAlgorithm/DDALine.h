#pragma once

#include "..\CourseCore\GraphicComponent.h"
#include "..\CourseCore\Vector2.h"
#include "..\CourseCore\Renderer2D.h"
#include <math.h>

class DDALine :
	public GraphicComponent
{
public:
	Vector2 start;
	Vector2 end;

	DDALine(Vector2 start, Vector2 end);
	~DDALine();

	virtual void Draw(std::shared_ptr<Renderer> renderer);
};

