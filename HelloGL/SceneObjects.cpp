#include "SceneObjects.h"

// setup mesh
SceneObjects::SceneObjects(Mesh* mesh, Texture2D* texture, Vector3 position, Vector3 rotation, Vector3 scale, Material* mat,SceneObjects* parent)
{
	objMesh = nullptr;	this->parent = parent;
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
	this->mesh = mesh;
	this->texture = texture;

	material = mat;
}

// setup obj mesh
SceneObjects::SceneObjects(OBJMesh* mesh, Texture2D* texture, Vector3 position, Vector3 rotation, Vector3 scale, Material* mat, SceneObjects* parent)
{
	this->parent = parent;
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
	this->mesh = nullptr;
	objMesh = mesh;
	this->texture = texture;

	material = mat;
}

SceneObjects::~SceneObjects(){}

void SceneObjects::Update(){}

void SceneObjects::Draw()
{
	glPushMatrix();
	
	glTranslatef(position.x, position.y, position.z);//sets position of object in scene

	//set rotation of object in scene
	glRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(rotation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(rotation.z, 0.0f, 0.0f, 1.0f);

	glScalef(scale.x, scale.y, scale.z);//set scale of object in scne

	//set material og object in scene
	glMaterialfv(GL_FRONT, GL_AMBIENT, &(material->Ambient.x));
	glMaterialfv(GL_FRONT, GL_SPECULAR, &(material->Specular.x));
	glMaterialfv(GL_FRONT, GL_DIFFUSE, &(material->Diffuse.x));
	glMaterialf(GL_FRONT, GL_SHININESS, material->Shininess);

	//draws mesh so long as data isn't empty
	if (!objMesh->vertices.empty() && !objMesh->normals.empty() && !objMesh->texCoords.empty() && !objMesh->indices.empty())
	{
		glBindTexture(GL_TEXTURE_2D, texture->GetID()); // binds texture to mesh
				
		// draws Suzanne to screen with normals, texture coordantes, and vertices
		glBegin(GL_TRIANGLES);
		for (int i = 0; i < objMesh->indices.size(); i++)
		{
			glTexCoord2fv(&objMesh->texCoords[objMesh->indices[i].texCoordIndex - 1].u);
			glNormal3fv(&objMesh->normals[objMesh->indices[i].normalIndex - 1].x);
			glVertex3fv(&objMesh->vertices[objMesh->indices[i].vertexIndex - 1].x);
		}
		glEnd();		
		glBindTexture(GL_TEXTURE_2D, 0); // binds texture to mesh
	}

	//loop though children calling their draw method, resulting in drawing them in relation to this object
	for (SceneObjects* child : children)
	{
		child->Draw();
	}

	glPopMatrix();
}
