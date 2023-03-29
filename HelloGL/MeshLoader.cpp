#include "MeshLoader.h"

#include <iostream>
#include <fstream>

using namespace std;

namespace MeshLoader
{
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);
	void LoadUV(ifstream& inFile, Mesh& mesh);

	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.VertexCount;

		// loop though vertex count assigning each vertex to the correct point in the array
		if (mesh.VertexCount > 0)
		{
			mesh.vertices = new Vertex[mesh.VertexCount];

			for (int i = 0; i < mesh.VertexCount; i++)
			{
				inFile >> mesh.vertices[i].x;
				inFile >> mesh.vertices[i].y;
				inFile >> mesh.vertices[i].z;
			}
		}
	}

	void LoadNormals(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.NormalCount;

		// loop though normal count assigning each normal to the correct point in the array
		if (mesh.VertexCount > 0)
		{
			mesh.Normals = new Vector3[mesh.NormalCount];

			for (int i = 0; i < mesh.NormalCount; i++)
			{
				inFile >> mesh.Normals[i].x;
				inFile >> mesh.Normals[i].y;
				inFile >> mesh.Normals[i].z;
			}
		}
	}	
	
	void LoadUV(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.texCoordsCount;

		// loop though texture coordanate count assigning each Texture coordanate to the correct point in the array
		if (mesh.texCoordsCount > 0)
		{
			mesh.texCoords = new TextureCoordanate[mesh.texCoordsCount];

			for (int i = 0; i < mesh.texCoordsCount; i++)
			{
				inFile >> mesh.texCoords[i].u;
				inFile >> mesh.texCoords[i].v;
			}
		}
	}

	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.IndexCount;

		// loop though index count assigning each index to the correct point in the array
		if (mesh.IndexCount > 0)
		{
			mesh.Indices = new GLshort[mesh.IndexCount];

			for (int i = 0; i < mesh.IndexCount; i++)
			{
				inFile >> mesh.Indices[i];
			}
		}
	}


	Mesh* MeshLoader::Load(char* path)
	{
		Mesh* mesh = new Mesh();

		ifstream inFile;
		inFile.open(path);

		// check if file opened without error
		if (!inFile.good())  
		{
			cerr  << "Can't open mesh file " << path << endl;
			return nullptr;
		}

		// load vertex data
		LoadVertices(inFile, *mesh);
		LoadUV(inFile, *mesh);
		LoadNormals(inFile, *mesh);
		LoadIndices(inFile, *mesh);

		inFile.close();

		return mesh;
	}
}