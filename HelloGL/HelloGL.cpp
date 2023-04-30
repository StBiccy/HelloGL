#include "HelloGL.h"

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
	glLoadIdentity();// replaces current martix with identity matrix
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
	OBJMesh* objMesh = OBJLoader::LoadOBJ((char*)"Meshes/world.obj");	

	// initilaise texture2D
	Texture2D* monkeyTex = new Texture2D();

	// initilise bitmap loader
	BitmapLoader* bitMapImage = new BitmapLoader();
	// create a raw file from bmp file
	bitMapImage->LoadBitMap((char*)"Textures/Monke.bmp", (char*)"Textures/Monke.raw");

	//Load monkey texture
	monkeyTex->Load((char*)"Textures/Monke.raw", 512, 512);

	// setup objects
	for (int i = 0; i < 60; i++)
	{
		objects[i] = new Suzanne(objMesh, monkeyTex, 0,0,0/*((rand() % 400) / 10.0f) - 20.0f, 0, -(rand() % 1000) / 10.0f*/);
	}

}

void HelloGL::InitLighting()
{
	// setup lightinhg position
	lightPositon = new Vector4();
	lightPositon->x = 0.0f;
	lightPositon->y = 10.0f;
	lightPositon->z = 1.0f;
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
	cameraRefrence = player->GetCamera();
}

void HelloGL::Update()
{
	glLoadIdentity();

	player->Update();

	// updates the scene objects every frame
	for (int i = 0; i < 1; i++)
	{
		objects[i]->Update();
	}		

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

	Vector3 v = { 0.0f,0.0f,0.0f };

	Colour c = { 0.0f,1.0f,0.0f };

	DrawString("Hello World Boy!", &v, &c);

	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);// switches back to the GL_MODELVIEW matrix so we can load our models
	glLoadIdentity();
	gluPerspective(45, 1, 1, 1000); // sets the correct perspective 
	gluLookAt(cameraRefrence->eye.x, cameraRefrence->eye.y, cameraRefrence->eye.z,
		cameraRefrence->frount.x + cameraRefrence->eye.x, cameraRefrence->frount.y + cameraRefrence->eye.y, cameraRefrence->frount.z + cameraRefrence->eye.z,
		cameraRefrence->up.x, cameraRefrence->up.y, cameraRefrence->up.z);



	// draws the scene objects every fram
	for (int i = 0; i < 60; i++)
	{
		objects[i]->Draw();
	}

	
	glLoadIdentity();


	glFlush();// empties all buffers, and preforms all issued commands
	glutSwapBuffers(); // swaps buffer of current window if double buffered
}

void HelloGL::DrawString(const char* text, Vector3* position, Colour* colour)
{

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
	int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
	glOrtho(0, windowWidth, 0, windowHeight, -1, -1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glDisable(GL_LIGHTING);

	glTranslatef(position->x, position->y, position->z);

	glColor3f(colour->r, colour->g, colour->b);
	glPushMatrix();
	glRasterPos2f(-0.9f,0.8f);
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
	delete objects;
	delete lightData;
	delete lightPositon;
}

void HelloGL::PassiveMotion(int x, int y)
{
	player->PassiveMotion(x, y);
}
