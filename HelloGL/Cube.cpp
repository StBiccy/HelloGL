#include "Cube.h"

Vertex* Cube::indexedVertices = nullptr;

Colour* Cube::indexedColours = nullptr;

GLushort* Cube::indices = nullptr;

int Cube::numVertices = 0;
int Cube::numColours = 0;
int Cube::numIndicies = 0;


Cube::Cube(GLfloat x, GLfloat y, GLfloat z)
{
	postition.x = x;
	postition.y = y;
	postition.z = z;

	

	rotation = 0.0f;
}

Cube::~Cube()
{

}

bool Cube::Load(char* path)
{
	std::ifstream inFile;
	inFile.open(path);
	if (!inFile.good())
	{
		std::cerr << "Can't open text file " << path << std::endl;
		return false;
	}

	inFile >> numVertices;
	indexedVertices = new Vertex[numVertices];
	for (int i = 0; i < numVertices; i++)
	{
		inFile >> indexedVertices[i].x;
		inFile >> indexedVertices[i].y;
		inFile >> indexedVertices[i].z;
	}

	inFile >> numColours;
	indexedColours = new Colour[numColours];
	for (int i = 0; i < numColours; i++)
	{
		inFile >> indexedColours[i].r;
		inFile >> indexedColours[i].g;
		inFile >> indexedColours[i].b;
	}

	inFile >> numIndicies;
	indices = new GLushort[numIndicies];
	for (int i = 0; i < numIndicies; i++)
	{
		inFile >> indices[i];
	}

	inFile.close();

	return true;
}

void Cube::Draw()
{
	if (indexedVertices != nullptr && indexedColours != nullptr && indices !=nullptr)
	{
		glTranslatef(postition.x, postition.y, postition.z);

		//glRotatef(rotation, 1.0f, 0.0f, 0.0f);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, indexedVertices);
		glColorPointer(3, GL_FLOAT, 0, indexedColours);

		glPushMatrix();
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indices);
		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
}

void Cube::Update()
{
	rotation += 0.1f;
}