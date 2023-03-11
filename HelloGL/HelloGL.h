#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GlU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"

#define REFRESHRATE 16


class HelloGL
{
private:
	float rotation;
	Camera* camera;

	Cube* cube;

	static Vertex vertices[];
	static Colour colours[];



public:
	HelloGL(int argc, char* argv[]);
	~HelloGL(void);
	void Display();

	void DrawTriangle();


	void Update();

	void Keyboard(unsigned char key, int x, int y);
};

