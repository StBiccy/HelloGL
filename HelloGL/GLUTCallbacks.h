#pragma once
class  HelloGL;

namespace GLUTCallbacks
{
	void Init(HelloGL* gl);//call back for initaliation
	void Display();//call back for display method
	void Timer(int preferedRefresh);//callback for timer method
	void KeyboardUp(unsigned char key, int x, int y);//callback for key up method
	void KeyboardDown(unsigned char key, int x, int y);//callback for key down method
	void PassiveMotion(int x, int y);//callback for mouse motion method
};

