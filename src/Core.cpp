#include "Core.h"

namespace core {
	Core::Core(GLuint width, GLuint height, GLfloat frameCap, BaseGame *game) :
		daemon(false)
	{
		this->frameTime = 1.0f / frameCap;
		this->height = height;
		this->width = width;
		this->game = game;

		if(glfwInit() == 0) {
			std::cerr << "GLFW failed at initialization." << std::endl;
		}
	}

	Core::~Core() {
		delete game;
		delete renderer;
		delete display;
	}

	void Core::CreateDisplay(std::string title) {
		display = new Display(width, height, title);

		glewExperimental = GL_TRUE;

		if(glewInit() != GLEW_OK) {
			std::cerr << "GLEW failed at initialization." << std::endl;
			glfwTerminate();
		}

		renderer = new Renderer();
		renderer->Create();
	}

	void Core::Start() {
		if(daemon) return;
		daemon = true;
		game->Create();
		game->ICreate();
		Run();

	}

	void Core::Run() {
		// TODO: create a proper main loop.

		do {
			game->Update();
			renderer->Render(game);
			display->Update();
		} while(!display->IsCloseRequested());

		Stop();
	}

	void Core::Stop() {
		daemon = false;
		glfwTerminate();
	}

} /* namespace core */