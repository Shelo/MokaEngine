#include <iostream>
#include "Core.h"
#include "BaseGame.h"
#include "Mesh.h"
#include <vector>
#include "Texture.h"
#include "Triangler.h"

class Game : public BaseGame {
public:
	Game() {

	}

	Texture *texture;

	void Create() {
		texture = new Texture("./res/textures/bricks2.jpg");
		texture->Bind();

		GameObject *p = new GameObject(10, 10);
		AddGameObject(p->AddComponent(new Triangler()));
	}

	~Game() {
		// Dont delete here gameobjects or components on the stage.
		delete texture;
	}
};

int main(int argc, char** argv) {
	core::Core core(640, 480, 60, new Game());
	core.CreateDisplay("Moka Engine");
	core.Start();

	system("pause");
	return 0;
}
