#include "SceneObjects.h"

// setup mesh
SceneObjects::SceneObjects(Mesh* mesh, Texture2D* texture)
{
	_objMesh = nullptr;
	_mesh = mesh;
	_texture = texture;
}

// setup obj mesh
SceneObjects::SceneObjects(OBJMesh* mesh, Texture2D* texture)
{
	_mesh = nullptr;
	_objMesh = mesh;
	_texture = texture;
}

SceneObjects::~SceneObjects(){}

void SceneObjects::Update(){}
void SceneObjects::Draw(){}
