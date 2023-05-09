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

	CharacterController(Vector3 pos, Vector3 front, Vector3 up);
	~CharacterController();

	void DirectionUpdate();//update camera direction

	void PassiveMotion(int x, int y);// update on mouse movement

	Camera GetCamera();
	Vector3 GetPosition() { return position; }

	void Update();
};

