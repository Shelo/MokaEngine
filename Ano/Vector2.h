#ifndef VECTOR2_H
#define VECTOR2_H

#include "GL\glew.h"

class Vector2 {
public:
	GLfloat x;
	GLfloat y;
	
	Vector2(GLfloat x, GLfloat y);

    Vector2& operator+=(const Vector2&);
    Vector2& operator+(const Vector2&);

    Vector2& operator-=(const Vector2&);
    Vector2& operator-(const Vector2&);

    Vector2& operator*=(const float);
    Vector2& operator*(const float);

    float Dot(const Vector2&);
    
    void Normalize();
    Vector2& Normalized();
};

#endif