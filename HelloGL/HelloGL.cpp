#include "HelloGL.h"


HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;

	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 100);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutMainLoop();
}

void HelloGL::Update()
{
	glutPostRedisplay();

	rotation += 0.5f;
	if (rotation >= 360)
	{
		rotation = 0.0f;
	}

}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	DrawPolygon();
	DrawTriangle();
	glFlush();
	glutSwapBuffers();
}

void HelloGL::DrawPolygon()
{
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);

	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
	glVertex2f(-0.75, 0.5);
	glVertex2f(0.75, 0.5);
	glColor4f(0.0f, 2.0f, 0.0f, 0.0f);
	glVertex2f(0.75, -0.5);
	glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
	glVertex2f(-0.75, -0.5);
	glEnd();

	glPopMatrix();
}

void HelloGL::DrawTriangle()
{
	glPushMatrix();
	glRotatef(rotation, 0.0f, 1.0f, 1.0f);

	glBegin(GL_POLYGON);
	glColor4f(0.3f, 0.0f, 0.5f, 0.0f);
	glVertex2f(-0.9, 0.7);
	glVertex2f(0.6, 0.5);
	glVertex2f(0.5, -0.3);
	glEnd();

	glPopMatrix();
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
		rotation += 0.5f;
	if (key == 'a')
		rotation -= 0.5f;
}


HelloGL::~HelloGL(void)
{

}
