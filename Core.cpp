#include "Core.h"

namespace core {
	Core::Core(GLuint width, GLuint height, GLfloat frameCap, BaseGame *game) {
		this->frameTime = 1.0f / frameCap;
		this->height = height;
		this->width = width;
		this->game = game;

		if(glfwInit() == false) {
			std::cerr << "GLFW failed at initialization." << std::endl;
		}
	}

	void Core::CreateDisplay(std::string title) {
		display = new Display(width, height, title);

		glewExperimental = GL_TRUE;

		if(glewInit() != GLEW_OK) {
			std::cerr << "GLEW failed at initialization." << std::endl;
			glfwTerminate();
		}
	}

	void Core::Start() {
		if(daemon) return;
		daemon = true;
		game->Create();
		game->Create2();
		Run();
	}

	void Core::Run() {
		// TODO: create a proper main loop.

		do {
			game->Update();
			game->Render();
			display->Update();
		} while(!display->IsCloseRequested());

		Stop();
	}

	void Core::Stop() {
		daemon = false;
		delete game;
		glfwTerminate();
	}

} /* namespace core */