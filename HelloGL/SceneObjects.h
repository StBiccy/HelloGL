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
	Mesh* mesh; // represents mesh to draw
	OBJMesh* objMesh; // represents obj mesh to draw
	Texture2D* texture; // represents texture data
public:
	Vector3 position;//position of object
	Vector3 rotation;//rotation of object
	Vector3 scale;//scale of object

	Material* material;//material of object

	std::vector<SceneObjects*> children;//attached childeren
	SceneObjects* parent;//object's parent


	SceneObjects(Mesh* mesh, Texture2D* texture, Vector3 position, Vector3 rotation, Vector3 scale, Material* mat, SceneObjects* parent = nullptr); // load for default mesh

	SceneObjects(OBJMesh* mesh, Texture2D* texture, Vector3 position, Vector3 rotation, Vector3 scale, Material* mat, SceneObjects* parent = nullptr); //load for obj mesh

	//adds child to object
	void AddChild(SceneObjects* child) 
	{ 
		children.push_back(child); 
		child->parent = this;
	}

	virtual ~SceneObjects();

	virtual void Update();
	virtual void Draw();
};

