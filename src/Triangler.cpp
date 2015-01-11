#include "Triangler.h"

Triangler::~Triangler() {
	delete mesh;
}

void Triangler::Create() {
	util::HeapArray<Vertex*> vs = util::HeapArray<Vertex*>::New({
		new Vertex(-1, -1, 0, 0, 0),
		new Vertex(0, 1, 0, 0.5, 1),
		new Vertex(1, -1, 0, 1, 0),
	});

	mesh = new Mesh(vs);
}

void Triangler::Render(Shader *shader) {
	shader->Update(GetTransform());
	mesh->Draw();
}