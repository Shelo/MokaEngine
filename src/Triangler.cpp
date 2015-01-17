#include "Triangler.h"
#include <vector>

Triangler::~Triangler() {
	delete material;
	delete mesh;
}

void Triangler::Create() {
	mesh = new Mesh("res/models/pyramid.obj");
	material = new Material(new Texture("res/textures/bricks2.jpg"), 1.0f, 1.0f, 1.0f, 1.0f);
	GetTransform().SetScale(28, 20, 28);
	GetTransform().Rotate(glm::vec3(0, 1, 0), glm::radians(45.0f));
}

void Triangler::Render(Shader &shader) {
	shader.Update(GetTransform(), *material);
	mesh->Draw();
}