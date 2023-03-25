#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GlU.h>
#include "GL\freeglut.h"

#include "Structures.h"


namespace OBJLoader
{
	OBJMesh* LoadOBJ(char* path);
};

