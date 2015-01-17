#ifndef MESH_H
#define MESH_H

#define GLEW_STATIC
#include <vector>
#include "GL/glew.h"
#include "Vertex.h"
#include "HeapArray.h"
#include <string>
#include <iostream>
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

class Mesh {
private:
	GLuint vao;
	GLuint ibo;
	GLuint vboPos;
	GLuint vboTex;
	GLuint vboNor;
	GLuint vboTan;
	GLuint count;

public:
	Mesh(util::HeapArray<Vertex*> &vertices, std::vector<int> indices);
	Mesh(const std::string& filePath);
	~Mesh();

	void Draw();
};

#endif