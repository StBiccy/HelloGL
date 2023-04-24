#pragma once
class  HelloGL;

namespace GLUTCallbacks
{
	void Init(HelloGL* gl);
	void Display();
	void Timer(int preferedRefresh);
	void KeyboardUp(unsigned char key, int x, int y);
	void KeyboardDown(unsigned char key, int x, int y);
	void PassiveMotion(int x, int y);
};

