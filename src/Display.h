#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#define GLFW_DLL
#include <GLFW/glfw3.h>

class Display {
public:
	Display(GLuint width, GLuint height, std::string title);
	void Update();
	bool IsCloseRequested();
	~Display();

	static GLuint GetWidth() { return width; }
	static GLuint GetHeight() { return height; }

private:
	GLFWwindow *window;
	static GLuint height;
	static GLuint width;
};

#endif