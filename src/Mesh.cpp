#include "Mesh.h"
#include <vector>

Mesh::Mesh(util::HeapArray<Vertex*> &vertices) :
		count((GLuint) vertices.Size()) {

	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texCoords;

	positions.reserve((size_t) vertices.Size());
	texCoords.reserve((size_t) vertices.Size());

	for(int i = 0; i < vertices.Size(); i++) positions.push_back(vertices[i]->GetPosition());
	for(int i = 0; i < vertices.Size(); i++) texCoords.push_back(vertices[i]->GetTexCoord());

	// generate the Vertex Array Object named VAO.
	glGenVertexArrays(1, &vao);

	// set the current Vertex Array to the VAO.
	glBindVertexArray(vao);

	// generate needed buffers for this mesh that will be included in the VAO.
	glGenBuffers(1, &vboPos);
	glGenBuffers(1, &vboTex);

	// VBO for Positions.
	glBindBuffer(GL_ARRAY_BUFFER, vboPos);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions[0]) * vertices.Size(), &positions[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);

	// VBO for TexCoords.
	glBindBuffer(GL_ARRAY_BUFFER, vboTex);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords[0]) * vertices.Size(), &texCoords[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);

	// unbind the vao.
	glBindVertexArray(0);
}

void Mesh::Draw() {
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, count);
	glBindVertexArray(0);
}

Mesh::~Mesh() {
	glDeleteVertexArrays(1, &vao);
}