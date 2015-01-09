#include "Mesh.h"
#include <vector>

Mesh::Mesh(util::HeapArray<Vertex*> &vertices) {
	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texCoords;

	for(size_t i = 0; i < vertices.Size(); i++) positions.push_back(vertices[i]->GetPosition());
	for(size_t i = 0; i < vertices.Size(); i++) texCoords.push_back(vertices[i]->GetTexCoord());

	// generate the Vertex Array Object named VAO.
	glGenVertexArrays(1, &vao);

	// set the current Vertex Array to the VAO.
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions[0]) * positions.size(), &positions[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 36);

	// unbind the vao.
	glBindVertexArray(0);
}

void Mesh::Draw() {
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}

Mesh::~Mesh() {

}