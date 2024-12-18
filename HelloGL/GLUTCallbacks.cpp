#include "GLUTCallbacks.h"
#include "HelloGL.h"

namespace GLUTCallbacks
{
	namespace
	{
		HelloGL* helloGL = nullptr;
	}

	void Init(HelloGL *gl)
	{
		helloGL = gl;
	}

	void Display()
	{
		if (helloGL != nullptr)
		{
			helloGL->Display();
		}
	}

	void Timer(int preferedRefesh)
	{
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		helloGL->Update();
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
		glutTimerFunc(preferedRefesh - updateTime, GLUTCallbacks::Timer, preferedRefesh);
	}

	void KeyboardUp(unsigned char key, int x, int y)
	{
		helloGL->KeyboardUp(key, x, y);
	}

	void KeyboardDown(unsigned char key, int x, int y)
	{
		helloGL->KeyboardDown(key, x, y);
	}

	void PassiveMotion(int x, int y)
	{
		helloGL->PassiveMotion(x, y);
	}
}