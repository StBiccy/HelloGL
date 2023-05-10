#include "HelloGL.h"
#include <string>
#include <sstream>
#include <iomanip>

HelloGL::HelloGL(int argc, char* argv[])
{

	InitGL(argc, argv);	// initialse opengl methods
	InitObjects(); // initialse objects
	InitLighting(); // initialse ligithing
	InitCharacter(); // initialse character
	glutMainLoop(); // start loop
}

void HelloGL::InitGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this); 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);// initialise window size
	glutInitWindowPosition(0, 100);// initialise window position
	glutCreateWindow("Simple OpenGL Program");// give window a title
	glutDisplayFunc(GLUTCallbacks::Display);// setup display fucntion
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);// setup timer fucntion

	glutKeyboardFunc(GLUTCallbacks::KeyboardDown);// setup keyboard inputs callbacks
	glutKeyboardUpFunc(GLUTCallbacks::KeyboardUp);// setup keyboard inputs callbacks
	glutPassiveMotionFunc(GLUTCallbacks::PassiveMotion);// setup for mouse position callbacks
	glutSetCursor(GLUT_CURSOR_NONE);// hides the Cursor 

	glMatrixMode(GL_PROJECTION);// switch to the GL_PROJECTION matrix mode for the following methods
	glLoadIdentity();// replaces current matix with identity matrix
	glViewport(0, 0, 800, 800);// set viewport to be entire window
	gluPerspective(45, 1, 1, 1000); // sets the correct perspective 
	glMatrixMode(GL_MODELVIEW);// switches back to the GL_MODELVIEW matrix so we can load our models
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

}

void HelloGL::InitObjects()
{
	// initialise obj mesh
	OBJMesh* Tree = OBJLoader::LoadOBJ((char*)"Meshes/Tree.obj");
	OBJMesh* Floor = OBJLoader::LoadOBJ((char*)"Meshes/Floor.obj");
	OBJMesh* Suzanne = OBJLoader::LoadOBJ((char*)"Meshes/suzan.obj");
	OBJMesh* Stand = OBJLoader::LoadOBJ((char*)"Meshes/Stand.obj");
	OBJMesh* SkyBox = OBJLoader::LoadOBJ((char*)"Meshes/SkyBox.obj");

	// initilaise texture2D
	Texture2D* treeTexture = new Texture2D();
	Texture2D* floorTexture = new Texture2D();
	Texture2D* suzanneTexture = new Texture2D();
	Texture2D* standTexture = new Texture2D();
	Texture2D* SkyBoxTexture = new Texture2D();

	// initilise bitmap loader
	BitmapLoader* bitMapImage = new BitmapLoader();
	// create a raw file from bmp file
	bitMapImage->LoadBitMap((char*)"Textures/Tree.bmp", (char*)"Textures/Tree.raw");
	bitMapImage->LoadBitMap((char*)"Textures/Floor.bmp", (char*)"Textures/Floor.raw");
	bitMapImage->LoadBitMap((char*)"Textures/Monke.bmp", (char*)"Textures/Monke.raw");
	bitMapImage->LoadBitMap((char*)"Textures/Stand.bmp", (char*)"Textures/Stand.raw");
	bitMapImage->LoadBitMap((char*)"Textures/SkyBox.bmp", (char*)"Textures/SkyBox.raw");

	//Load texture
	treeTexture->Load((char*)"Textures/Tree.raw", 256, 256);
	floorTexture->Load((char*)"Textures/Floor.raw", 256, 256);
	suzanneTexture->Load((char*)"Textures/Monke.raw", 512, 512);
	standTexture->Load((char*)"Textures/Stand.raw", 1024, 1024);
	SkyBoxTexture->Load((char*)"Textures/SkyBox.raw", 1024, 1024);

	//Load materals
	defaultMaterial = new Material();
	defaultMaterial->Ambient = { 0.5f,0.5f,0.5f,0.5f };
	defaultMaterial->Diffuse = { 1.0f,1.0f,1.0f,1.0f };
	defaultMaterial->Specular = { 0.0f,0.0f,0.0f,0.0f };
	defaultMaterial->Shininess = 0.0f;

	treeMaterial = new Material();
	treeMaterial->Ambient = { 0.5f,0.5f,0.5f,0.5f };
	treeMaterial->Diffuse = { 1.0f,1.0f,1.0f,1.0f };
	treeMaterial->Specular = { 0.8f,0.0f,0.0f,0.0f };
	treeMaterial->Shininess = 0.0f;

	monkeMaterial = new Material();
	monkeMaterial->Ambient = { 1.0f,1.0f,1.0f,0.5f };
	monkeMaterial->Diffuse = { 1.0f,1.0f,1.0f,1.0f };
	monkeMaterial->Specular = { 0.0f,3.0f,7.0f,0.0f };
	monkeMaterial->Shininess = 0.0f;

	// setup objects
	for (int i = 0; i < 60; i++)
	{
		trees[i] = new SceneObjects(Tree, treeTexture, { ((rand() % 2500) / 10.0f), 0, -(rand() % 2500) / 10.0f }, {0,0,0},{1,1,1}, treeMaterial);
	}

	stand = new SceneObjects(Stand, standTexture, { 130,0,-130 }, { 0,0,0 }, { 3,3,3 }, defaultMaterial);
	suzanne = new SceneObjects(Suzanne, suzanneTexture, { 0,4,0 }, { 0,0,0 }, { 1,1,1 }, monkeMaterial);

	stand->AddChild(suzanne);

	floor = new SceneObjects(Floor, floorTexture, { 0,0,0 }, { 0,0,0 }, { 1,1,1 }, defaultMaterial);
	skyBox = new SceneObjects(SkyBox, SkyBoxTexture, { 0,0,0 }, { 0,0,0 }, {1,1,1}, defaultMaterial);
	


	delete bitMapImage;
}

void HelloGL::InitLighting()
{
	// setup lightinhg position
	lightPositon = new Vector4();
	lightPositon->x = 50.0f;
	lightPositon->y = 100.0f;
	lightPositon->z = 50.0f;
	lightPositon->w = 0.0f;

	// set up lighting data
	lightData = new Lighting();
	lightData->Ambient.x = 0.2f;
	lightData->Ambient.y = 0.2f;
	lightData->Ambient.z = 0.2f;
	lightData->Ambient.w = 1.0f;
	lightData->Diffuse.x = 0.8f;
	lightData->Diffuse.y = 0.8f;
	lightData->Diffuse.z = 0.8f;
	lightData->Diffuse.w = 1.0f;
	lightData->Specular.x = 0.2f;
	lightData->Specular.y = 0.2f;
	lightData->Specular.z = 0.2f;
	lightData->Specular.w = 1.0f;
}

void HelloGL::InitCharacter()
{
	//initalise the player character
	player = new CharacterController(0.0f, 5.0f, 5.0f, 0.0f, 0.0f, -5.0f, 0.0f, 1.0f, 0.0f);
}

void HelloGL::Update()
{
	glMatrixMode(GL_PROJECTION);// switch to the GL_PROJECTION matrix mode for the following methods
	glLoadIdentity();// replaces current matix with identity matrix
	gluPerspective(45, 1, 1, 1000); // sets the correct perspective 

	player->Update();

	suzanne->rotation.y += 1;

	skyBox->position = player->GetPosition();

	//sets the light up every frame
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(lightData->Ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(lightData->Diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(lightData->Specular.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(lightPositon->x));
	glutPostRedisplay();// updateds display method
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// clears the colour bit buffer, and depth bit buffer
	

	// draws the scene objects every fram
	for (int i = 0; i < 60; i++)
	{
		trees[i]->Draw();
	}

	floor->Draw();

	stand->Draw();
	glDisable(GL_LIGHTING);

	glColor3f(1, 1, 1);
	skyBox->Draw();
	glEnable(GL_LIGHTING);
	
	// Draw string for ui bellow these \/
	glLoadIdentity();// replaces current matix with identity matrix
	glOrtho(0, 800, 800, 0, 0, 1.0f);

#pragma region Text stuff
	Vector2 v = { 10.0f,30.0f };
	Colour c = { 0.0f,1.0f,0.0f };
	Vector3 position = player->GetPosition();
	std::ostringstream stream;

	stream << "X: ";
	stream << std::fixed;
	stream << std::setprecision(2);
	stream << position.x;
	stream.width(5);

	stream << "Y: ";
	stream << std::fixed;
	stream << std::setprecision(2);
	stream << position.y;
	stream.width(5);

	stream << "Z: ";
	stream << std::fixed;
	stream << std::setprecision(2);
	stream << position.z;

	DrawString(stream.str().c_str(), &v, &c);

	int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);

	microSec += (timeSinceStart - oldTime);
	oldTime = timeSinceStart;
	if (microSec >= 1000)
	{
		microSec -= 1000;
		++sec;
		if (sec >= 60)
		{
			sec -= 60;
			++min;
			if (min >= 60)
			{
				min -= 60;
				++hour;
			}
		}
	}

	std::string string = "Time in scene: " + std::to_string(hour) + " : " + std::to_string(min) + " : " + std::to_string(sec) + " : " + std::to_string(microSec);

	v = { 10,65 };

	DrawString(string.c_str(), &v, &c);
#pragma endregion
	glFlush();// empties all buffers, and preforms all issued commands
	glutSwapBuffers(); // swaps buffer of current window if double buffered
}

void HelloGL::DrawString(const char* text, Vector2* position, Colour* colour)
{
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glColor3f(colour->r, colour->g, colour->b);
	glRasterPos2f(position->x, position->y);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void HelloGL::KeyboardUp(unsigned char key, int x, int y)
{
	// set a bool for which keys are down in the player script
	if (key == 'w')
	{
		player->wDown = false;
	}
	else if (key == 's')
	{
		player->sDown = false;

	}
	else if (key == 'a')
	{
		player->aDown = false;

	}
	else if (key == 'd')
	{
		player->dDown = false;
	}
}

void HelloGL::KeyboardDown(unsigned char key, int x, int y)
{
	// set a bool for which keys are up in the player script
	if (key == 'w')
	{
		player->wDown = true;
	}	
	else if (key == 's')
	{
		player->sDown = true;
	}
	else if (key == 'a')
	{
		player->aDown = true;

	}
	else if (key == 'd')
	{
		player->dDown = true;
	}
}

HelloGL::~HelloGL(void)
{
	delete player;
	delete trees;
	delete floor;
	delete lightData;
	delete lightPositon;
	delete defaultMaterial;
	delete treeMaterial;
	delete monkeMaterial;
}

void HelloGL::PassiveMotion(int x, int y)
{
	player->PassiveMotion(x, y);
}
