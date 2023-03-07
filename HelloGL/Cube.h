#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"

class Cube
{
private:

	static Vertex indexedVertices[];
	static Colour indexedColours[];
	static GLushort indices[];

	GLfloat rotation;

	Vector3 position;

public:
	Cube(float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
};

