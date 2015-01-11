#include "Display.h"

Display::Display(GLuint width, GLuint height, std::string title) {
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	if(!window) {
		std::cerr << "Ventana weona" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
}

void Display::Update() {
	glfwSwapBuffers(window);
	glfwPollEvents();
}

bool Display::IsCloseRequested() {
	return glfwWindowShouldClose(window);
}

Display::~Display() {
}
