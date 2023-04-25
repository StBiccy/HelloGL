#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GlU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "Mathf.h"

#define SPEED 1.0f

class CharacterController
{
private:
	Vector3 position;// represent position in world
	Vector3 velocity;// represent velocity
	Camera* cam;// represent camera

	float pitch;// represents rotation in the x axis
	float yaw;// represents rotation in the y axis

	float sensitivity;// represents camera sensitiviy

public:
	// input checks
	bool wDown;
	bool aDown;
	bool sDown;
	bool dDown;

	CharacterController(float posX, float posY, float posZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ);
	~CharacterController();

	void DirectionUpdate();//update camera direction

	void PassiveMotion(int x, int y);// update on mouse movement

	void Update();
};

