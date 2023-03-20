#include "Cube.h"


Cube::Cube(Mesh* mesh, GLfloat x, GLfloat y, GLfloat z) : SceneObjects(mesh)
{
	postition.x = x;
	postition.y = y;
	postition.z = z;

	rotation = 0.0f;
}

Cube::~Cube()
{

} 

void Cube::Draw()
{
	if (_mesh->vertices != nullptr && _mesh->colours != nullptr && _mesh->Indices !=nullptr)
	{

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->vertices);
		glColorPointer(3, GL_FLOAT, 0, _mesh->colours);

		glPushMatrix();
			glTranslatef(postition.x, postition.y, postition.z);
			glRotatef(rotation, postition.x, postition.y, postition.z);
			glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->Indices);
		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
}

void Cube::Update()
{
	rotation += 0.1f;
}