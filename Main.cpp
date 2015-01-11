<<<<<<< HEAD
#include "Core.h"
=======
#include <iostream>
#include "Core.h"
#include "BaseGame.h"
#include "Mesh.h"
#include <vector>
>>>>>>> 3ef377a769b287de0d5c00b006d08d7e4aefc667
#include "Texture.h"
#include "Triangler.h"

class Transformer : public Component {
public:
	void Create() {
		GetTransform()->GetScale()->x *= 0.5f;
		GetTransform()->GetScale()->y *= 0.5f;
		GetTransform()->GetScale()->z *= 0.5f;
	}

	void Update() {
		GetTransform()->GetRotation()->y += 3.1415f / 1500.0f;
	}
};

class Game : public BaseGame {
public:
	Texture *texture;

	void Create() {
<<<<<<< HEAD
		texture = new Texture("res/textures/bricks2.jpg");
=======
		texture = new Texture("./res/textures/bricks2.jpg");
>>>>>>> 3ef377a769b287de0d5c00b006d08d7e4aefc667
		texture->Bind();

		GameObject *p = new GameObject(0.0f, 0.0f);
		p->AddComponent(new Transformer());
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
<<<<<<< HEAD
=======

	system("pause");
>>>>>>> 3ef377a769b287de0d5c00b006d08d7e4aefc667
	return 0;
}
