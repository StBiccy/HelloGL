#pragma once

#include "GLUTCallbacks.h"
#include "Cube.h"
#include "Pyramid.h"
#include "Suzanne.h"
#include "Structures.h"
#include "MeshLoader.h"
#include "BitmapLoader.h"
#include "OBJLoader.h"
#include "CharacterController.h"
#define REFRESHRATE 16


class HelloGL
{
private:
	Camera* camera;

	CharacterController* player;

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
	void InitCharacter();

	void Update();

	void KeyboardDown(unsigned char key, int x, int y);
	void KeyboardUp(unsigned char key, int x, int y);
	void PassiveMotion(int x, int y);
};

