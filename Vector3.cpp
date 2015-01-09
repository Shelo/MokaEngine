#include "Vector3.h"


Vector3::Vector3(GLfloat x, GLfloat y, GLfloat z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(GLfloat x, GLfloat y) : Vector3(x, y, 0) {}