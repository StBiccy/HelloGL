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
	// represents position
	Vector3 postition;

	// represents rotation
	GLfloat rotation;

	// represents mateiral
	Material* material;

public:
	Cube(Mesh* mesh, Texture2D* texture, GLfloat x, GLfloat y, GLfloat z);
	~Cube();

	void Update();
	void Draw();
};

