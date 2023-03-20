#include "Texture2D.h"
#include <iostream>
#include <fstream>

Texture2D::Texture2D()
{

}

Texture2D::~Texture2D()
{
	glDeleteTextures(1, &ID);
}

bool Texture2D::Load(char* path, int width, int height)
{
	 _width = width;
	 _height = height;

	 std::ifstream inFile;
	 char* tempTexData;
	 int fileSize;

	 inFile.open(path, std::ios::binary);

	 if (!inFile.good())
	 {
		 std::cerr << "Can't open texture file: " << path << std::endl;
		 return false;
	 }

	 inFile.seekg(0, std::ios::end); //Seek end of file;
	 fileSize = (int)inFile.tellg(); //Get the current postion (the end) and set the file size to equal that - this gives us the total file size
	 tempTexData = new char[fileSize]; //Creates an array to store data
	 inFile.seekg(0, std::ios::beg); //Sends to the begining of the file
	 inFile.read(tempTexData, fileSize); //Read in all data in one go
	 inFile.close();

	 std::cout << "Loaded" << std::endl;

	 glGenTextures(1, &ID); //Gen next texture ID
	 glBindTexture(GL_TEXTURE_2D, ID); //Bind the texture to teh ID
	 gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, tempTexData); //Specify the details of our texture image

	 delete[] tempTexData;
	 return true;
}