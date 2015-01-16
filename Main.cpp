#include "Core.h"
#include "Triangler.h"
#include "Input.h"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

class CameraMove : public Component {
public:
	void Create() {
		Input::SetCursorLocked(true);
	}

	void Update(double delta) {
		if(Input::GetKey(GLFW_KEY_A))
			GetTransform().Move(GetTransform().GetLeft(), (float) delta * 10);

		if(Input::GetKey(GLFW_KEY_D))
			GetTransform().Move(GetTransform().GetRight(), (float) delta * 10);

		if(Input::GetKey(GLFW_KEY_W))
			GetTransform().Move(GetTransform().GetForward(), (float) delta * 10);

		if(Input::GetKey(GLFW_KEY_S))
			GetTransform().Move(GetTransform().GetBack(), (float) delta * 10);

		GetTransform().Rotate(glm::vec3(0, -1, 0), (float const) (Input::GetDeltaX() * delta * 0.2f));
		GetTransform().Rotate(GetTransform().GetLeft(), (float const) (Input::GetDeltaY() * delta * 0.2f));

		if(Input::GetMouseDown(GLFW_MOUSE_BUTTON_1))
			Input::ToggleCursorLocked();
	}
};

class OnePlane : public Component {
private:
	Material *material;
	Mesh *mesh;
public:
	~OnePlane() {
		delete material;
		delete mesh;
	}

	void Create() {
		util::HeapArray<Vertex*> vs = util::HeapArray<Vertex*>::New ({
				new Vertex(-1, 0, -1, 0, 0),
				new Vertex( 1, 0, -1, 10, 0),
				new Vertex( 1, 0,  1, 10, 10),
				new Vertex(-1, 0,  1, 0, 10),
		});

		std::vector<int> indices {
				0, 1, 2,
				0, 2, 3,
		};

		mesh = new Mesh(vs, indices);

		material = new Material(new Texture("res/textures/grass.jpg"), 1.0f, 1.0f, 1.0f, 1.0f);
	}

	void Render(Shader &shader) {
		shader.Update(GetTransform(), *material);
		mesh->Draw();
	}
};

class Game : public BaseGame {
public:
	void Create() {
		// Here i'll create the plane of the scene, this is done by the OnePlane component.
		GameObject *p = new GameObject(0, 0, 0);
		p->GetTransform().SetScale(100, 1, 100);
		AddGameObject(p->AddComponent(new OnePlane()));

		// 3 simple pyramids.
		GameObject *w = new GameObject(-40, 0, -10);
		AddGameObject(w->AddComponent(new Triangler()));

		GameObject *j = new GameObject( 40, 0, -10);
		AddGameObject(j->AddComponent(new Triangler()));

		GameObject *k = new GameObject( 0, 0, -50);
		AddGameObject(k->AddComponent(new Triangler()));

		// This defines a new camera attached to a game object, this camera will follow the position of the
		// GameObject.
		// Note: if you want to uncomment this you'll have to adjust the size within the Transformer component and
		// the position of the game object.
		GameObject *q = new GameObject(0.0f, 2.0f, 40.0f);
		q->AddComponent(new CameraMove());
		Camera *camera = new Camera(70.0f, 1.3333f, 0.01f, 1000.0f);
		camera->SetCurrent();

		q->AddComponent(camera);

		AddGameObject(q);

		/*
		// Test using ASSIMP.
		Assimp::Importer importer;
		const aiScene* scene = importer.ReadFile("res/models/monke3.obj",
				aiProcess_CalcTangentSpace |
				aiProcess_Triangulate |
				aiProcess_JoinIdenticalVertices);

		if(!scene) {
			std::cout << "File corrupted." << std::endl;
		} else {
			std::cout << "File imported correctly." << std::endl;
		}
		*/
	}

	~Game() {
		// Don't delete here GameObjects or Components, objects will delete them automatically.
	}
};

int main(int argc, char** argv) {
	// Here i'll limit the Frame Rate to 60 fps, just so process is not that expensive,
	// you could try 5000 per example and surely will work better. Note that at 60, you'll probably
	// get 60 FPS and 60 UPS. Also, turn of the lowCPU option.
	core::Core core(640, 480, 60, new Game());
	core.CreateDisplay("Moka Engine");

	glClearColor(0, 0, 0, 1);

	// this method activates a way to reduce drastically the cpu usage. Anyway, is not recommended and
	// shouldn't be used in a release, use it for dev only.
	core.SetLowCPU(true);

	core.Start();
	return 0;
}
