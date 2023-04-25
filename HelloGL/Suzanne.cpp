#include "Suzanne.h"

Suzanne::Suzanne(OBJMesh* mesh, Texture2D* texture, GLfloat x, GLfloat y, GLfloat z) : SceneObjects(mesh, texture)
{
	postition.x = x;
	postition.y = y;
	postition.z = z;

	rotation = 0.0f;
}

Suzanne::~Suzanne()
{

}

void Suzanne::Draw()
{
	if (!_objMesh->vertices.empty() && !_objMesh->normals.empty() && !_objMesh->texCoords.empty() && !_objMesh->indices.empty())
	{
		glBindTexture(GL_TEXTURE_2D, _texture->GetID()); // binds texture to mesh

		glPushMatrix();
		glTranslatef(postition.x, postition.y, postition.z);// sets postition of Suzanne
		//glRotatef(rotation, 1, 1, 1);// sets rotation of Suzanne

		// draws Suzanne to screen with normals, texture coordantes, and vertices
		glBegin(GL_TRIANGLES);
		for (int i = 0; i < _objMesh->indices.size(); i++)
		{
			glTexCoord2fv(&_objMesh->texCoords[_objMesh->indices[i].texCoordIndex - 1].u);
			glNormal3fv(&_objMesh->normals[_objMesh->indices[i].normalIndex - 1].x);
			glVertex3fv(&_objMesh->vertices[_objMesh->indices[i].vertexIndex - 1].x);
		}
		glEnd();

		glPopMatrix();
	}
}

void Suzanne::Update()
{
	rotation += 0.5f;// updates rotation every frame
}