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
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);		

		glPushMatrix();
		glTranslatef(postition.x, postition.y, postition.z);
		glRotatef(rotation, 1, 1, 1);

		glBegin(GL_TRIANGLES);
		for (int i = 0; i < _objMesh->indices.size(); i++)
		{
			glTexCoord2f(_objMesh->texCoords[_objMesh->indices[i].texCoordIndex - 1].u, _objMesh->texCoords[_objMesh->indices[i].texCoordIndex - 1].v);
			glNormal3f(_objMesh->normals[_objMesh->indices[i].normalIndex - 1].x, _objMesh->normals[_objMesh->indices[i].normalIndex - 1].y, _objMesh->normals[_objMesh->indices[i].normalIndex - 1].z);
			glVertex3f(_objMesh->vertices[_objMesh->indices[i].vertexIndex - 1].x, _objMesh->vertices[_objMesh->indices[i].vertexIndex - 1].y, _objMesh->vertices[_objMesh->indices[i].vertexIndex - 1].z);
		}
		glEnd();

		glPopMatrix();

		
	}
}

void Suzanne::Update()
{
	rotation += 0.5f;
}