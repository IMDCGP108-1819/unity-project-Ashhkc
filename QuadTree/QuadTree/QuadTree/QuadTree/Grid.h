#pragma once

#include "GL\glew.h"

class Grid
{
public:
	Grid();
	~Grid();

	void Initialize(float x, float y, float width, float height);

	void Draw();

private:
	float _x, _y, _width, _height;
	GLuint _vboID;
};

