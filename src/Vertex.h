#ifndef VERTEX_H
#define VERTEX_H

#include "GL/glew.h"
#include "glm/vec3.hpp"
#include "glm/vec2.hpp"

class Vertex {
private:
	glm::vec3 position;
	glm::vec2 texCoord;
public:
	Vertex(GLfloat x, GLfloat y, GLfloat z, GLfloat s, GLfloat t) :
		position(x, y, z),
		texCoord(s, t) {}

	Vertex(GLfloat x, GLfloat y, GLfloat z) :
		position(x, y, z),
		texCoord(0, 0) {}

	Vertex() :
			position(0, 0, 0),
			texCoord(0, 0) {}

	glm::vec3& GetPosition() { return position; };
	glm::vec2& GetTexCoord() { return texCoord; };
};

#endif