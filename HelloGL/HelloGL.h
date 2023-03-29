#pragma once

#include "GLUTCallbacks.h"
#include "Cube.h"
#include "Pyramid.h"
#include "Suzanne.h"
#include "Structures.h"
#include "MeshLoader.h"
#include "BitmapLoader.h"
#include "OBJLoader.h"

#define REFRESHRATE 16


class HelloGL
{
private:
	Camera* camera;

	

	SceneObjects* objects[60];

	Vector4* lightPositon;
	Lighting* lightData;

public:
	HelloGL(int argc, char* argv[]);
	~HelloGL(void);
	void Display();

	void InitLighting();
	void InitObjects();
	void InitGL(int argc, char* argv[]);

	void Update();

	void Keyboard(unsigned char key, int x, int y);
};

