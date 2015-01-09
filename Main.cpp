#include <iostream>
#include "Core.h"
#include "BaseGame.h"

class Game : public BaseGame {
public:
	Game() {

	}

	~Game() {

	}

	GLuint vaoID;
	GLuint vboID;

	void Create() {
		// Generate VAO.
		glGenVertexArrays(1, &vaoID);
		glBindVertexArray(vaoID);

		static const GLfloat vertx[] = {
			-1, -1, 0,
			1, -1, 0,
			0, 1, 0,
		};

		glGenBuffers(1, &vboID);
		glBindBuffer(GL_ARRAY_BUFFER, vboID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertx), vertx, GL_STATIC_DRAW);
	}

	void TempUpdate() {
		glEnableVertexAttribArray(0);

		glBindVertexArray(vboID);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glDisableVertexAttribArray(0);
	}
};

int main(int argc, char** argv) {
	core::Core core(640, 480, 60, new Game());
	core.CreateDisplay("My Window");
	core.Start();

	return 0;
}
