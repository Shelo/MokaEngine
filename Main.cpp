#include <iostream>
#include "Core.h"
#include "BaseGame.h"
#include "Mesh.h"
#include <vector>
#include "Triangler.h"

class Game : public BaseGame {
public:
	Game() {

	}

	void Create() {
		GameObject *p = new GameObject(10, 10);
		AddGameObject(p->AddComponent(new Triangler()));
	}

	~Game() {
		// Dont delete here gameobjects or components on the stage.
	}
};

int main(int argc, char** argv) {
	core::Core core(640, 480, 60, new Game());
	core.CreateDisplay("Moka Engine");
	core.Start();

	system("pause");
	return 0;
}
