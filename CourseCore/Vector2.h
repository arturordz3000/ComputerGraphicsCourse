#pragma once

#ifdef COURSECORE_EXPORTS
#define COURSECORE_API __declspec(dllexport)
#else
#define COURSECORE_API __declspec(dllimport)
#endif

class COURSECORE_API Vector2
{
public:
	Vector2();
	Vector2(int x, int y);
	~Vector2();

	int x;
	int y;
};

