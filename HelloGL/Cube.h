#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GlU.h>
#include "GL\freeglut.h"
#include "SceneObjects.h"

#include <fstream>
#include <iostream>

class Cube : public SceneObjects
{
private:

	Vector3 postition;

	GLfloat rotation;


public:
	Cube(Mesh* mesh, Texture2D* texture, GLfloat x, GLfloat y, GLfloat z);
	~Cube();

	void Update();
	void Draw();
};

