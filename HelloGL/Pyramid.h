#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GlU.h>
#include "GL\freeglut.h"
#include "SceneObjects.h"

#include <fstream>
#include <iostream>

class Pyramid : public SceneObjects
{
private:

	Vector3 postition;

public:
	Pyramid(Mesh* mesh, GLfloat x, GLfloat y, GLfloat z);
	~Pyramid();

	void Update();
	void Draw();
};


