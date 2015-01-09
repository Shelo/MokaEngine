#ifndef VECTOR3_H
#define VECTOR3_H

#include "GL\glew.h"

class Vector3 {
public:
	GLfloat x;
	GLfloat y;
	GLfloat z;
	
	Vector3(GLfloat x, GLfloat y, GLfloat z);
	Vector3(GLfloat x, GLfloat y);

	Vector3& operator+=(const Vector3&);
    Vector3& operator+(const Vector3&);

    Vector3& operator-=(const Vector3&);
    Vector3& operator-(const Vector3&);

    Vector3& operator*=(const float);
    Vector3& operator*(const float);

    float Dot(const Vector3&);
    
    void Normalize();
    Vector3& Normalized();
};

#endif