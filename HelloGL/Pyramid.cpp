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
	if (_mesh->vertices != nullptr && _mesh->Normals != nullptr && _mesh->Indices != nullptr)
	{
		//setup data for vertices on pyramid
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->vertices);

		glPushMatrix();
		glTranslatef(postition.x, postition.y, postition.z);//set rotation
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->Indices);// draw pyramid
		glPopMatrix();

		// disabled the previously enabled client states
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
}

void Pyramid::Update()
{

}