#ifndef VECTOR2_H
#define VECTOR2_H

#include "GL\glew.h"

class Vector2 {
public:
	Vector2(GLfloat x, GLfloat y);
private:
	GLfloat x;
	GLfloat y;
};

#endif