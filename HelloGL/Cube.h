#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GlU.h>
#include "GL\freeglut.h"
#include "Structures.h"

class Cube
{
private:
	static Vertex indexedVertices[];
	static Colour indexedColours[];
	static GLushort indices[];

	GLfloat rotation;


public:
	Cube();
	~Cube();

	void Update();
	void Draw();
};

