#include "Core.h"
#include "Texture.h"
#include "Triangler.h"
#include "Input.h"

class CameraMove : public Component {
public:
	void Create() {

	}

	void Update(double delta) {
		if(Input::GetKey(GLFW_KEY_A))
			GetTransform().GetPosition().x -= delta * 10;

		if(Input::GetKey(GLFW_KEY_D))
			GetTransform().GetPosition().x += delta * 10;

		if(Input::GetKey(GLFW_KEY_W))
			GetTransform().GetPosition().z -= delta * 10;

		if(Input::GetKey(GLFW_KEY_S))
			GetTransform().GetPosition().z += delta * 10;
	}
};

class OnePlane : public Component {
private:
	Mesh *mesh;
public:
	~OnePlane() {
		delete mesh;
	}

	void Create() {
		util::HeapArray<Vertex*> vs = util::HeapArray<Vertex*>::New ({
				new Vertex(-1, 0, -1, 0, 0),
				new Vertex( 1, 0,  1, 10, 10),
				new Vertex(-1, 0,  1, 0, 10),

				new Vertex(-1, 0, -1, 0, 0),
				new Vertex( 1, 0, -1, 10, 0),
				new Vertex( 1, 0,  1, 10, 10),
		});

		mesh = new Mesh(vs);
	}

	void Render(Shader &shader) {
		shader.Update(GetTransform());
		mesh->Draw();
	}
};

class Game : public BaseGame {
public:
	Texture *texture;

	void Create() {
		texture = new Texture("res/textures/bricks2.jpg");
		texture->Bind();

		GameObject *p = new GameObject(0, 0, 0);
		AddGameObject(p->AddComponent(new OnePlane()));

		p->GetTransform().SetScale(100, 1, 100);

		GameObject *w = new GameObject(-30, 0, -30);
		AddGameObject(w->AddComponent(new Triangler()));

		GameObject *j = new GameObject( 30, 0, -30);
		AddGameObject(j->AddComponent(new Triangler()));

		// This defines a new camera attached to a game object, this camera will follow the position of the
		// GameObject.
		// Note: if you want to uncomment this you'll have to adjust the size within the Transformer component and
		// the position of the game object.
		GameObject *q = new GameObject(0.0f, 5.0f, 40.0f);
		q->AddComponent(new CameraMove());
		Camera *camera = new Camera(70.0f, 1.3333f, 0.01f, 1000.0f);
		camera->SetCurrent();

		q->AddComponent(camera);

		AddGameObject(q);
	}

	~Game() {
		// Don't delete here GameObjects or Components, objects will delete them automatically.
		delete texture;
	}
};

int main(int argc, char** argv) {
	// Here i'll limit the Frame Rate to 60 fps, just so process is not that expensive,
	// you could try 5000 per example and surely with work. Note that at 60, you'll probably
	// get 60 FPS and 60 UPS.
	core::Core core(640, 480, 60, new Game());
	core.CreateDisplay("Moka Engine");

	glClearColor(0, 0, 0, 1);

	core.Start();
	return 0;
}
