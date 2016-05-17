#pragma once

#ifdef COURSECORE_EXPORTS
#define COURSECORE_API __declspec(dllexport)
#else
#define COURSECORE_API __declspec(dllimport)
#endif

class COURSECORE_API Renderer
{
public:
	Renderer();
	~Renderer();
};

