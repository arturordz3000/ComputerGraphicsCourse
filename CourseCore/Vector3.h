#pragma once

#ifdef COURSECORE_EXPORTS
#define COURSECORE_API __declspec(dllexport)
#else
#define COURSECORE_API __declspec(dllimport)
#endif

class COURSECORE_API Vector3
{
public:
	float x, y, z;

	Vector3();
	Vector3(float x, float y, float z);
	~Vector3();
};

