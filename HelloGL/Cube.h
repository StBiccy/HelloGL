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

	Vector3 postition;

	GLfloat rotation;


public:
	Cube(GLfloat x, GLfloat y, GLfloat z);
	~Cube();

	void Update();
	void Draw();
};

