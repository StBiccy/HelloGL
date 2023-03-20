#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GlU.h>
#include "GL\freeglut.h"
#include "Structures.h"



namespace MeshLoader
{
	Mesh* Load(char* path);
};

