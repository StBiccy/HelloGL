#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GlU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include <fstream>
#include <iostream>

class Cube
{
private:
	static Vertex* indexedVertices;
	static Colour* indexedColours;
	static GLushort* indices;

	static int numVertices, numColours, numIndicies;

	Vector3 postition;

	GLfloat rotation;


public:
	Cube(GLfloat x, GLfloat y, GLfloat z);
	~Cube();

	static bool Load(char* path);


	void Update();
	void Draw();
};

