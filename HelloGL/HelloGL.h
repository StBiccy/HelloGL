#pragma once

#include "GLUTCallbacks.h"
#include "Cube.h"
#include "Pyramid.h"
#include "Structures.h"

#define REFRESHRATE 16


class HelloGL
{
private:

	Camera* camera;

	SceneObjects* objects[200];

public:
	HelloGL(int argc, char* argv[]);
	~HelloGL(void);
	void Display();

	void InitObjects();
	void InitGL(int argc, char* argv[]);

	void Update();

	void Keyboard(unsigned char key, int x, int y);
};

