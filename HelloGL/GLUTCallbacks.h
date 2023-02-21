#pragma once
class  HelloGL;

namespace GLUTCallbacks
{
	void Init(HelloGL* gl);
	void Display();
	void Timer(int preferedRefresh);
	void Keyboard(unsigned char key, int x, int y);
};

