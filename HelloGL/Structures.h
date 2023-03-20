#pragma once

// represents a point in the 3D space
struct Vector3
{
	float x;
	float y;
	float z;
};

//represents a camera
struct Camera
{
	Vector3 eye;// where the eye/postion of the camera is placed
	Vector3 center; // where the center/focal point of the camera is
	Vector3 up; //represents the rotation of the camera/where the upwards direction of it is
};

// represents a colour
struct Colour
{
	GLfloat r, g, b;
};

// repesents a point in 3D space for a vertex to be placed
struct Vertex
{
	GLfloat x, y, z;
};

struct TextureCoordanate
{
	GLfloat u, v;
};

struct Mesh
{
	Vertex* vertices;
	Colour* colours;
	GLshort* Indices;
	TextureCoordanate* texCoords;
	int VertexCount, ColourCount, texCoordsCount, IndexCount;
};