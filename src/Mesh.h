#ifndef MESH_H
#define MESH_H

#define GLEW_STATIC

#include <vector>
#include "GL/glew.h"
#include "Vertex.h"
#include "HeapArray.h"

class Mesh {
private:
	GLuint vao;
	GLuint ibo;
	GLuint vboPos;
	GLuint vboTex;
	GLuint count;

public:
	Mesh(util::HeapArray<Vertex*> &vertices, std::vector<int> indices);
	~Mesh();

	void Draw();
};

#endif