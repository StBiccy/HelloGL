#pragma once
#include <vector>

// represents a 2D vector
struct Vector2
{
	float x;
	float y;
};

// represents a 3D vector
struct Vector3
{
	float x;
	float y;
	float z;
};

// represents a 4D vector
struct Vector4
{
	float x;
	float y;
	float z;
	float w;
};

//represents a camera
struct Camera
{
	Vector3 eye;// where the eye/postion of the camera is placed
	Vector3 front; // represents the direction the camera is looking
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

//represnts a uv coordanates
struct TextureCoordanate
{
	GLfloat u, v;
};

// represents a face on a mesh
struct Face
{
	GLint vertexIndex;
	GLint texCoordIndex;
	GLint normalIndex;
};

// represents lighting data
struct Lighting
{
	Vector4 Ambient;
	Vector4 Diffuse;
	Vector4 Specular;
};

// represents material data
struct Material
{
	Vector4 Ambient;
	Vector4 Diffuse;
	Vector4 Specular;
	GLfloat Shininess;
};

// represents a basic mesh
struct Mesh
{
	Vertex* vertices;
	Vector3* Normals;
	GLshort* Indices;
	TextureCoordanate* texCoords;
	int VertexCount, NormalCount, texCoordsCount, IndexCount;
};

//represnts a mesh loaded from an obj file
struct OBJMesh
{
	std::vector<Vertex> vertices;
	std::vector<Vector3> normals;
	std::vector<TextureCoordanate> texCoords;

	std::vector<Face> indices;
};