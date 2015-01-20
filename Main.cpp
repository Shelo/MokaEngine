#include "light/DirectionalLight.h"
#include "MeshRenderer.h"
#include "Input.h"
#include "Core.h"

class CameraMove : public Component {
public:
	void Create() {
		Input::SetCursorLocked(true);
	}

	void Update(double delta) {
		// Behavior for WASD keys.
		if(Input::GetKey(GLFW_KEY_A)) GetTransform().Move(GetTransform().GetLeft(),    (float) delta * 25);
		if(Input::GetKey(GLFW_KEY_D)) GetTransform().Move(GetTransform().GetRight(),   (float) delta * 25);
		if(Input::GetKey(GLFW_KEY_W)) GetTransform().Move(GetTransform().GetForward(), (float) delta * 25);
		if(Input::GetKey(GLFW_KEY_S)) GetTransform().Move(GetTransform().GetBack(),    (float) delta * 25);

		// Rotate with cursor delta.
		GetTransform().Rotate(glm::vec3(0, -1, 0), (float const) (Input::GetDeltaX() * delta * 0.2f));
		GetTransform().Rotate(GetTransform().GetLeft(), (float const) (Input::GetDeltaY() * delta * 0.2f));

		// Toggle Cursor Lock when mouse presses the left button.
		if(Input::GetMouseDown(GLFW_MOUSE_BUTTON_1)) Input::ToggleCursorLocked();
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
		mesh = new Mesh("res/models/plane.obj");

		material = new Material(new Texture("res/textures/wood.jpg"), glm::vec3(1.0f, 1.0f, 1.0f));
		material->SetNormalMap(new Texture("res/textures/wood_normal.jpg"));
		material->SetSpecular(2, 16);
		material->SetTiling(50, 50);
	}

	void Render(Shader &shader) {
		shader.Update(GetTransform(), *material);
		mesh->Draw();
	}
};

class SampleMesh : public Component {
private:
	Material *material;
	Mesh *mesh;
public:
	~SampleMesh() {
		delete material;
		delete mesh;
	}

	void Create() {
		mesh = new Mesh("res/models/cube.obj");
		material = new Material(new Texture("res/textures/ice.jpg"), glm::vec3(1.0f, 1.0f, 1.0f));
		material->SetNormalMap(new Texture("res/textures/ice_normal.jpg"));
		material->SetSpecular(1, 16);
	}

	void Update(double delta) {
		GetTransform().Rotate(glm::vec3(0, -1, 0), (float const) (1.0f * delta));
	}

	void Render(Shader &shader) {
		shader.Update(GetTransform(), *material);
		mesh->Draw();
	}
};

class Pyramid : public Component {
private:
	Material *material;
	Mesh *mesh;
public:
	~Pyramid() {
		delete material;
		delete mesh;
	}

	void Create() {
		mesh = new Mesh("res/models/pyramid.obj");
		material = new Material(new Texture("res/textures/wood.jpg"), glm::vec3(1.0f, 1.0f, 1.0f));
		material->SetTiling(2, 2);
		material->SetNormalMap(new Texture("res/textures/floor_normal.jpg"));

		GetTransform().SetScale(28, 20, 28);
		GetTransform().Rotate(glm::vec3(0, 1, 0), glm::radians(45.0f));
	}

	void Render(Shader &shader) {
		shader.Update(GetTransform(), *material);
		mesh->Draw();
	}
};

class SkyBox : public Component {
private:
	Material *material;
	Mesh *mesh;
public:
	~SkyBox() {
		delete material;
		delete mesh;
	}

	void Create() {
		mesh = new Mesh("res/models/skyBoxCube.obj");
		material = new Material(new Texture("res/textures/skybox.jpg"), glm::vec3(1.0f, 1.0f, 1.0f));
		GetTransform().SetScale(500, 500, 500);
	}

	void Render(Shader &shader) {
		shader.Update(GetTransform(), *material);
		mesh->Draw();
	}
};

class Game : public BaseGame {
public:
	void Create() {
		// Plane.
		GameObject *p = new GameObject(0, 0, 0);
		p->GetTransform().SetScale(100, 1, 100);
		AddGameObject(p->AddComponent(new OnePlane()));

		// Fortress.
		GameObject *k = new GameObject( 0, 0, 0);
		Mesh* mesh = new Mesh("res/models/fortress.obj");
		Material* mat = new Material(new Texture("res/textures/bricks.jpg"), glm::vec3(1.0f, 1.0f, 1.0f));
		mat->SetNormalMap(new Texture("res/textures/bricks_normal.jpg"));
		AddGameObject(k->AddComponent(new MeshRenderer(*mesh, *mat)));
		k->GetTransform().Rotate(glm::vec3(0, -1, 0), glm::radians(90.0f));

		// Cube.
		GameObject *s = new GameObject(0, 2, 0);
		s->GetTransform().SetScale(1, 1, 1);
		AddGameObject(s->AddComponent(new SampleMesh()));

		// Directional Light.
		AddGameObject((new GameObject())->AddComponent(new DirectionalLight(glm::vec3(1.0f, 1.0f, 1.0f), 0.6f, glm::vec3(-1.0f, -1.0f, -1.0f))));

		// This defines a new camera attached to a game object, this camera will follow the position of the
		// GameObject.
		// Note: if you want to uncomment this you'll have to adjust the size within the Transformer component and
		// the position of the game object.
		GameObject *q = new GameObject(0.0f, 2.0f, 40.0f);
		q->AddComponent(new CameraMove());
		Camera *camera = new Camera(70.0f, Display::GetWidth() / (float) Display::GetHeight(), 0.01f, 1000.0f);
		camera->SetCurrent();
		q->AddComponent(camera);
		q->AddComponent(new SkyBox());
		AddGameObject(q);
	}

	~Game() {
		// Don't delete here GameObjects or Components, objects will delete them automatically.
	}
};

int main(int argc, char** argv) {
	// Here i'll limit the Frame Rate to 100 fps, just so process is not that expensive,
	// you could try 5000 per example and surely will work better. Note that at 60, you'll probably
	// get 60 FPS and 60 UPS. Also, turn of the lowCPU option.
	core::Core core(1280, 720, 100, new Game());
	core.CreateDisplay("Moka Engine");

	// this method activates a way to reduce drastically the cpu usage. Anyway, is not recommended and
	// shouldn't be used in a release, use it for dev only.
	core.SetLowCPU(true);

	// Here could be a good place for render, physics, etc, settings.
	Moka::SetAmbientLight(0.2f, 0.2f, 0.2f);
	Moka::SetClearColor(0, 0, 0);

	core.Start();
	return 0;
}
