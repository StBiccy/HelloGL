#include "SceneObjects.h"


SceneObjects::SceneObjects(Mesh* mesh, Texture2D* texture)
{
	_mesh = mesh;
	_texture = texture;
}
SceneObjects::~SceneObjects(){}

void SceneObjects::Update(){}
void SceneObjects::Draw(){}
