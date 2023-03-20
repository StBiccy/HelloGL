#include "Pyramid.h"

Pyramid::Pyramid(Mesh* mesh, GLfloat x, GLfloat y, GLfloat z) : SceneObjects(mesh, nullptr)
{
	postition.x = x;
	postition.y = y;
	postition.z = z;

}

Pyramid::~Pyramid()
{

}

void Pyramid::Draw()
{
	if (_mesh->vertices != nullptr && _mesh->colours != nullptr && _mesh->Indices != nullptr)
	{

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->vertices);
		glColorPointer(3, GL_FLOAT, 0, _mesh->colours);

		glPushMatrix();
		glTranslatef(postition.x, postition.y, postition.z);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->Indices);
		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
}

void Pyramid::Update()
{

}