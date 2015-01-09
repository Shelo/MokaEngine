#ifndef CORE_H
#define CORE_H

#include "Display.h"
#include "BaseGame.h"

namespace core {

	class Core {
	public:
		Core(GLuint width, GLuint height, GLfloat frameCap, BaseGame *game);
		void CreateDisplay(std::string title);
		void Start();
		~Core();
	private:
		void Run();

		Display *display;
		GLfloat frameTime;
		BaseGame *game;
		GLuint height;
		GLuint width;
		bool daemon;
	};

}

#endif