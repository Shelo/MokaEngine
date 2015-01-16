#include "Mesh.h"

Mesh::Mesh(util::HeapArray<Vertex*> &vertices, std::vector<int> indices) :
		count((GLuint) indices.size()) {

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
	glGenBuffers(1, &ibo);

	// Buffer for Positions.
	glBindBuffer(GL_ARRAY_BUFFER, vboPos);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions[0]) * vertices.Size(), &positions[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);

	// Buffer for TexCoords.
	glBindBuffer(GL_ARRAY_BUFFER, vboTex);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords[0]) * vertices.Size(), &texCoords[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);

	// Buffer for indices.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

	// unbind the vao.
	glBindVertexArray(0);
}

void Mesh::Draw() {
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

Mesh::~Mesh() {
	glDeleteVertexArrays(1, &vao);
}