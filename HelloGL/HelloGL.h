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
	int oldTime = 0;//represents time in last frame
	unsigned short microSec = 0;//represents current micro seconds in scene
	byte min = 0;//represents current minuets in scene
	byte sec = 0;//represents curents seconds in scene
	int hour = 0;//represents current hour in scene

	CharacterController* player; // represents the player character

	//Scene objects for every mesh in the scene
	SceneObjects* trees[60]; 
	SceneObjects* floor;
	SceneObjects* stand;
	SceneObjects* suzanne;
	SceneObjects* skyBox;

	//materials for all mateirals in the scene
	Material* defaultMaterial;
	Material* treeMaterial;
	Material* monkeMaterial;

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

	void DrawString(const char* text, Vector2* position, Colour* colour);//call for drawing the string;
};

