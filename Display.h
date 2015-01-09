#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <GL/glew.h>
#define GLFW_DLL
#include <GLFW\glfw3.h>

class Display {
public:
	Display(GLuint width, GLuint height, std::string title);
	void Update();
	bool IsCloseRequested();
	~Display();
private:
	GLFWwindow *window;
};

#endif