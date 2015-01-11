#ifndef MESH_H
#define MESH_H

#define GLEW_STATIC
#include "GL/glew.h"
#include "Vertex.h"
#include "HeapArray.h"

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