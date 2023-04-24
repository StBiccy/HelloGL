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

	float pitch;
	float yaw;

	float sensitivity;

protected:


public:
	// input checks
	bool wDown;
	bool aDown;
	bool sDown;
	bool dDown;

	CharacterController(float posX, float posY, float posZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ);
	~CharacterController();

	void DirectionUpdate();

	void PassiveMotion(int x, int y);


	void Update();
};

