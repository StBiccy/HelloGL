#pragma once
#include <list>
#include <memory>

#include "SceneObjects.h"
#include "Structures.h"
#include "mat4.h"

class Entity : public SceneObjects
{

public:
	Transform transfrom;

	Entity(OBJMesh* mesh, Texture2D* texture) : SceneObjects(mesh, texture){}

	std::list<std::unique_ptr<Entity>> children;


	template<typename TArgs>
	void addChild(const TArgs& args)
	{
		children.emplace_back(std::make_unique<Entity>(args));
		children.back()->parent = this;
	}


};

