#include "Display.h"
#include "Input.h"

GLuint Display::height = 0;
GLuint Display::width = 0;

Display::Display(GLuint width, GLuint height, std::string title) {
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	Display::height = height;
	Display::width = width;

	if(!window) {
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);

	Input::Create(window);
}

void Display::Update() {
	glfwSwapBuffers(window);
	glfwPollEvents();
}

bool Display::IsCloseRequested() {
	return (bool) glfwWindowShouldClose(window);
}

Display::~Display() {

}
