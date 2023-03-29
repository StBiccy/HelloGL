#include "Cube.h"


Cube::Cube(Mesh* mesh, Texture2D* texture, GLfloat x, GLfloat y, GLfloat z) : SceneObjects(mesh, texture)
{
	postition.x = x;
	postition.y = y;
	postition.z = z;

	rotation = 0.0f;
}

Cube::~Cube()
{
	delete material;
} 

void Cube::Draw()
{
	if (_mesh->vertices != nullptr && _mesh->Normals != nullptr && _mesh->Indices != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());// binds the texture

		//setup data for vertices on cube
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->vertices);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normals);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->texCoords);

		// assign material to cube
		material = new Material();
		material->Ambient.x = 0.8f; material->Ambient.y = 0.05f; material->Ambient.z = 0.05f; material->Ambient.w = 1.0f;
		material->Diffuse.x = 0.8f; material->Diffuse.y = 0.05f; material->Diffuse.z = 0.05f; material->Diffuse.w = 1.0f;
		material->Specular.x = 1.0f; material->Specular.y = 1.0f; material->Specular.z = 1.0f; material->Specular.w = 1.0f;
		material->Shininess = 100.0f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(material->Ambient.x));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(material->Diffuse.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(material->Specular.x));
		glMaterialf(GL_FRONT, GL_SHININESS, material->Shininess);

		glPushMatrix();

		glTranslatef(postition.x, postition.y, postition.z);// set positon
		glRotatef(rotation, 1, 1, 1);// set rotation

		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->Indices);// draws the cube

		glPopMatrix();

		// disable the enabled client states
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

void Cube::Update()
{
	// updates the rotation everyframe
	rotation += 0.4f;
}