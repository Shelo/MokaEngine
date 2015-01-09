#ifndef CORE_H
#define CORE_H

#include "Display.h"
#include "BaseGame.h"
#include "Renderer.h"

namespace core {
	
	class Core {
	public:
		Core(GLuint width, GLuint height, GLfloat frameCap, BaseGame *game);
		virtual ~Core();
		void CreateDisplay(std::string title);
		void Start();
		void Stop();
	private:
		void Run();

		Renderer *renderer;
		Display *display;
		BaseGame *game;

		GLfloat frameTime;
		GLuint height;
		GLuint width;
		bool daemon;
	};

}

#endif