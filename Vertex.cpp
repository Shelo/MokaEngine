#include "Vertex.h"


Vertex::Vertex(GLfloat x, GLfloat y, GLfloat z, GLfloat s, GLfloat t) {
	position = new Vector3(x, y, z);
}

Vertex::~Vertex() {
	delete position;
}
