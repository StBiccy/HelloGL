#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	InitGL(argc, argv);
	InitObjects();

	glutMainLoop();
}

void HelloGL::InitGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 100);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glMatrixMode(GL_PROJECTION);// switch to the GL_PROJECTION matrix mode for the following methods
	glLoadIdentity();// replaces current matix with identity matrix
	glViewport(0, 0, 800, 800);// set viewport to be entire window
	gluPerspective(45, 1, 0.1, 1000); // sets the correct perspective 
	glMatrixMode(GL_MODELVIEW);// switches back to the GL_MODELVIEW matrix so we can load our models
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
}

void HelloGL::InitObjects()
{

	camera = new Camera();

	camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -100.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	Mesh* pyramidMesh = MeshLoader::Load((char*)"pyramid.txt");

	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");

	for (int i = 0; i < 500; i++)
	{
		objects[i] = new Cube(cubeMesh,((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
	for (int i = 500; i < 1000; i++)
	{
		objects[i] = new Pyramid(pyramidMesh, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
}


void HelloGL::Update()
{
	glLoadIdentity(); //resets the ideity matrix at the start of every frame
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z); //refreshes what the camera is looking at

	// updates the cubes every frame
	for (int i = 0; i < 1000; i++)
	{
		objects[i]->Update();
	}

	glutPostRedisplay();


}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	for (int i = 0; i < 1000; i++)
	{
		objects[i]->Draw();
	}

	glFlush();
	glutSwapBuffers();
}


void HelloGL::Keyboard(unsigned char key, int x, int y)
{

}

HelloGL::~HelloGL(void)
{

	delete camera;

	for (int i = 0; i < 1000; i++)
	{
		delete objects[i];
	}
}
