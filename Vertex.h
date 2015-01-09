#ifndef VERTEX_H
#define VERTEX_H

#include "GL\glew.h"
#include "Vector3.h"
#include "Vector2.h"

class Vertex {
public:
	Vertex(GLfloat x, GLfloat y, GLfloat z, GLfloat s, GLfloat t);
	Vertex(GLfloat x, GLfloat y, GLfloat z);
	~Vertex();
private:
	Vector3 *position;
	Vector2 *texCoords;
};

#endif