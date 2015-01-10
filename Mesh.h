#ifndef MESH_H
#define MESH_H

#include "Vertex.h"
#include "HeapArray.h"
#include <vector>

class Mesh {
private:
	GLuint vao;
	GLuint vboPos;
	GLuint vboTex;

public:
	Mesh(util::HeapArray<Vertex*> &vertices);
	~Mesh();

	void Draw();
};

#endif