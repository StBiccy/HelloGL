#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GlU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "Texture2D.h"

class SceneObjects
{
protected:
	Mesh* _mesh;
	Texture2D* _texture;

public:
	SceneObjects(Mesh* mesh, Texture2D* texture);

	virtual ~SceneObjects();

	virtual void Update();
	virtual void Draw();
};

