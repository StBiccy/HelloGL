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
	Mesh* _mesh; // represents mesh to draw
	OBJMesh* _objMesh; // represents obj mesh to draw
	Texture2D* _texture; // represents texture data
public:
	SceneObjects(Mesh* mesh, Texture2D* texture); // load for default mesh

	SceneObjects(OBJMesh* mesh, Texture2D* texture); //load for obj mesh

	virtual ~SceneObjects();

	virtual void Update();
	virtual void Draw();
};

