#include "Vector2.h"


Vector2::Vector2(GLfloat x, GLfloat y) {
	this->x = x;
	this->y = y;
}

Vector2& Vector2::operator+=(const Vector2& other) {
	x += other.x;
	y += other.y;
	return *this;
}

Vector2& Vector2::operator+(const Vector2& other) {
	return *(new Vector2(x + other.x, y + other.y));
}

Vector2& Vector2::operator-=(const Vector2& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2& Vector2::operator-(const Vector2& other) {
	return *(new Vector2(x - other.x, y - other.y));
}

Vector2& Vector2::operator*=(const float scalar)  {
	x *= scalar;
	y *= scalar;
	return *this;
}


Vector2& Vector2::operator*(const float scalar) {
	return *(new Vector2(x * scalar, y * scalar));
}

float Dot(const Vector2& other) {
	return x * other.x + y * other.y;
}

void Vector2::Normalize() {
	float factor = (float) sqrt(x * x + y * y);
    x /= factor;
    y /= factor;
}

Vector2& Vector2::Normalized() {
    float factor = (float) sqrt(x * x + y * y);
    return *(new Vector2(x / factor, y / factor));
}