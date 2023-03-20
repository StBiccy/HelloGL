#pragma once
#include "MeshLoader.h"

class SceneObjects
{
protected:
	Mesh* _mesh;

public:
	SceneObjects(Mesh* mesh);

	virtual ~SceneObjects();

	virtual void Update();
	virtual void Draw();
};

