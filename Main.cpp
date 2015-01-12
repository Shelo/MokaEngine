#include "Core.h"
#include "Texture.h"
#include "Triangler.h"

class Transformer : public Component {
public:
	void Create() {
		GetTransform().GetScale().x *= 100.0f;
		GetTransform().GetScale().y *= 100.0f;
		GetTransform().GetScale().z *= 100.0f;
	}

	void Update(double delta) {
		GetTransform().GetRotation().z += 3.1415f * delta;
	}
};

class Game : public BaseGame {
public:
	Texture *texture;

	void Create() {
		texture = new Texture("res/textures/bricks2.jpg");
		texture->Bind();

		GameObject *p = new GameObject(Display::GetWidth() / 2, Display::GetHeight() / 2);
		p->AddComponent(new Transformer());
		AddGameObject(p->AddComponent(new Triangler()));

		/*
		// This defines a new camera attached to a game object, this camera will follow the position of the
		// GameObject.
		// Note: if you want to uncomment this you'll have to adjust the size within the Transformer component.
		GameObject *q = new GameObject(0.0f, 0.0f, -3.0f);

		Camera *camera = new Camera(70.0f, 1.3333f, 0.01f, 1000.0f);
		camera->SetCurrent();

		std::cout << camera << std::endl;

		q->AddComponent(camera);

		AddGameObject(q);
		*/
	}

	~Game() {
		// Don't delete here GameObjects or components on the stage.
		delete texture;
	}
};

int main(int argc, char** argv) {
	// Here i'll limit the Frame Rate to 60 fps, just so process is not that expensive,
	// you could try 5000 per example and surely with work. Note that at 60, you'll probably
	// get 60 FPS and 60 UPS.
	core::Core core(640, 480, 60, new Game());
	core.CreateDisplay("Moka Engine");
	core.Start();
	return 0;
}
