#pragma once

#include "GLUTCallbacks.h"
#include "SceneObjects.h"
#include "Structures.h"
#include "MeshLoader.h"
#include "BitmapLoader.h"
#include "OBJLoader.h"
#include "CharacterController.h"
#define REFRESHRATE 16


class HelloGL
{
private:
	CharacterController* player; // represnts the player character

	SceneObjects* trees[60]; // represents all scene objects
	SceneObjects* floor;
	SceneObjects* stand;
	SceneObjects* suzanne;
	SceneObjects* skyBox;

	Vector4* lightPositon; // represents the lighting position
	Lighting* lightData; // represnets the light data

public:
	HelloGL(int argc, char* argv[]);
	~HelloGL(void);
	void Display(); // updates the display

	void InitLighting(); // initilise lighting
	void InitObjects(); // initilise objects
	void InitGL(int argc, char* argv[]); // intilise the GL methods
	void InitCharacter(); // initilise character

	void Update(); // update scene

	void KeyboardDown(unsigned char key, int x, int y); // update on key press
	void KeyboardUp(unsigned char key, int x, int y); // update on key release
	void PassiveMotion(int x, int y); // update on mouse motiion

	void DrawString(const char* text, Vector3* position, Colour* colour);//call for drawing the string;
};

