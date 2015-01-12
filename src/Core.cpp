#include "Core.h"
#include "Input.h"

#if defined(WIN32)
#include "windows.h"
#elif defined(UNIX)
#include <unistd.h>
#endif

namespace core {
	Core::Core(GLuint width, GLuint height, GLfloat frameCap, BaseGame *game) :
		daemon(false)
	{
		this->frameTime = 1.0f / frameCap;
		this->height = height;
		this->width = width;
		this->game = game;

		lowCPU = false;

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
		// total time accumulated in the game.
		double time = 0.0;

		// fixed delta time.
		const double delta = frameTime;

		// current time var and accumulator.
		double currentTime = glfwGetTime();
		double accumulator = 0.0;

		// this is just to show some statics.
		int updateFrames = 0;
		int renderFrames = 0;
		double accSeconds = 0;

		while(daemon) {
			// indicates if we should render or not.
			bool render = false;

			// get the time that the render frame lasted.
			double newTime = glfwGetTime();
			double frameTime = newTime - currentTime;
			currentTime = newTime;

			// increase the accumulator by this frame time.
			accumulator += frameTime;

			// "spend" the accumulator time until is lower than the delta time.
			// while we have time accumulated left, we update the scene.
			while(accumulator > delta) {
				// we'll need to render only if we updated the scene... obviously.
				render = true;

				game->Update(delta);

				Input::Update();

				// check if user closed the window.
				if(display->IsCloseRequested())
					daemon = false;

				// subtract used delta time and add it to the game time.
				accumulator -= delta;
				time += delta;
				accSeconds += delta;

				updateFrames++;
			}

			// when the accumulator is over, render and update the display.
			if(render) {
				renderFrames++;
				renderer->Render(game);
				display->Update();
			} else if(lowCPU)
				// compile time if statement, if lowCPU setting is enabled, the machine is intended
				// to sleep for at least 1 millisecond. Shouldn't be used in a release, since is not
				// guaranteed that this will sleep 1 millisecond and could affect the experience.
				#if defined(WIN32)
				Sleep(1);
				#elif defined(UNIX)
				usleep(1000);
				#endif

			if(accSeconds >= 1) {
				std::cout << renderFrames << " fps, " << updateFrames << " ups." << std::endl;
				accSeconds = renderFrames = updateFrames = 0;
			}
		}

		Stop();
	}

	void Core::Stop() {
		daemon = false;
		glfwTerminate();
	}
} /* namespace core */