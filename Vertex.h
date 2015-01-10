#ifndef VERTEX_H
#define VERTEX_H

#include "GL/glew.h"
#include "glm/vec3.hpp"
#include "glm/vec2.hpp"

class Vertex {
private:
	glm::vec3 *position;
	glm::vec2 *texCoord;
public:
	Vertex(GLfloat x, GLfloat y, GLfloat z, GLfloat s, GLfloat t);
	Vertex(GLfloat x, GLfloat y, GLfloat z);
	~Vertex();

	static Vertex &New(GLfloat x, GLfloat y, GLfloat z, GLfloat s, GLfloat t);
	static Vertex &New(GLfloat x, GLfloat y, GLfloat z);

	static const GLuint SIZE = 5;

	glm::vec3 GetPosition() const;
	glm::vec2 GetTexCoord() const;
};

#endif