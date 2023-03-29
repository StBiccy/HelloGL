#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GlU.h>
#include "GL\freeglut.h"

class Texture2D
{
private:
	GLuint ID;
	int _width, _height; //width and hight of the texture

public:
	Texture2D();
	~Texture2D();

	bool Load(char* path, int width, int height);// load the texture from file path, and width/hight

	GLuint GetID() const { return ID; }// returns the id of the texture
	int GetWidth() const { return _width; }// returns the width of the texture
	int GetHeight() const { return _height; }// returns the hight of the texture

};

