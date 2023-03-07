#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GlU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"

#define REFRESHRATE 16

struct Vector3
{
	float x;
	float y;
	float z;
};

struct Camera
{
	Vector3 eye;
	Vector3 center;
	Vector3 up;
};

struct Colour
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat x, y, z;
};

class HelloGL
{
private:
	float rotation;
	Camera* camera;
	float cameraEyeZpos;
	float cameraEyeXpos;
	float cameraCenterZ;
	float cameraCenterX;

	static Vertex vertices[];
	static Colour colours[];

	static Vertex indexedVertices[];
	static Colour indexedColours[];
	static GLushort indices[];

public:
	HelloGL(int argc, char* argv[]);
	~HelloGL(void);
	void Display();
	void DrawPolygon();
	void DrawTriangle();

	void DrawCube();
	void DrawCubeArray();
	void DrawIndexedCube();

	void DrawIndexedCubeAlt();

	void Update();

	void Keyboard(unsigned char key, int x, int y);
};

