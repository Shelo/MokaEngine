#include "Vertex.h"

Vertex::Vertex(GLfloat x, GLfloat y, GLfloat z, GLfloat s, GLfloat t) {
	position = new glm::vec3(x, y, z);
	texCoord = new glm::vec2(s, t);
}

Vertex::Vertex(GLfloat x, GLfloat y, GLfloat z) : Vertex(x, y, z, 0, 0) {}

Vertex& Vertex::New(GLfloat x, GLfloat y, GLfloat z, GLfloat s, GLfloat t) {
	return *(new Vertex(x, y, z, s, t));
}

Vertex& Vertex::New(GLfloat x, GLfloat y, GLfloat z) {
	return *(new Vertex(x, y, z));
}

glm::vec3 Vertex::GetPosition() const {
	return *position;
}

glm::vec2 Vertex::GetTexCoord() const {
	return *texCoord;
}

Vertex::~Vertex() {
	delete position;
	delete texCoord;
}
