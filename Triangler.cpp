#include "Triangler.h"

Triangler::~Triangler() {
	delete mesh;
}

void Triangler::Create() {
	util::HeapArray<Vertex*> vs = util::HeapArray<Vertex*>::New({
		new Vertex(-1, -1, 0),
		new Vertex(1, -1, 0),
		new Vertex(0, 1, 0),
	});

	mesh = new Mesh(vs);
}

void Triangler::Render() {
	mesh->Draw();
}