#ifndef MESH_H
#define MESH_H

#include "Vertex.h"
#include "HeapArray.h"

class Mesh {
private:
	GLuint vbo;
	GLuint vao;

public:
	Mesh(util::HeapArray<Vertex*> &vertices);
	~Mesh();

	void Draw();
};

#endif