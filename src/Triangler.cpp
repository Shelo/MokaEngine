#include "Triangler.h"

Triangler::~Triangler() {
	delete material;
	delete mesh;
}

void Triangler::Create() {
	util::HeapArray<Vertex*> vs = util::HeapArray<Vertex*>::New({
			new Vertex(0, 2, 0, 0.5f, 1),
			new Vertex(1, 0, 1, 0, 0),
			new Vertex(-1, 0, 1, 1, 0),

			new Vertex(0, 2, 0, 0.5f, 1),
			new Vertex(1, 0, -1, 1, 0),
			new Vertex(1, 0, 1, 0, 0),

			new Vertex(0, 2, 0, 0.5f, 1),
			new Vertex(-1, 0, -1, 1, 0),
			new Vertex(1, 0, -1, 0, 0),

			new Vertex(0, 2, 0, 0.5f, 1),
			new Vertex(-1, 0, 1, 1, 0),
			new Vertex(-1, 0, -1, 0, 0),
	});

	mesh = new Mesh(vs);

	material = new Material(new Texture("res/textures/bricks2.jpg"), 1.0f, 1.0f, 1.0f, 1.0f);

	GetTransform().SetScale(20, 20, 20);
}

void Triangler::Render(Shader &shader) {
	shader.Update(GetTransform(), *material);
	mesh->Draw();
}