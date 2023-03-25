#pragma once
#include "SceneObjects.h"

class Suzanne : public SceneObjects
{
private:

	Vector3 postition;

	GLfloat rotation;

	Material* material;

public:
	Suzanne(OBJMesh* mesh, Texture2D* texture, GLfloat x, GLfloat y, GLfloat z);
	~Suzanne();

	void Update();
	void Draw();

};

