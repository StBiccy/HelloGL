#pragma once
#include "SceneObjects.h"

class Suzanne : public SceneObjects
{
private:

	Vector3 postition; // represents position of Suzanne

	GLfloat rotation;// represents rotation of Suzanne

	Material* material; // represents material of Suzanne

public:
	Suzanne(OBJMesh* mesh, Texture2D* texture, GLfloat x, GLfloat y, GLfloat z);
	~Suzanne();

	void Update();
	void Draw();

};

