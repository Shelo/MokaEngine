#include "Vector3.h"

Vector3::Vector3(GLfloat x, GLfloat y, GLfloat z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(GLfloat x, GLfloat y) : Vector3(x, y, 0) {}

Vector3& Vector3::operator+=(const Vector3& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

Vector3& Vector3::operator+(const Vector3& other) {
	return *(new Vector3(x + other.x, y + other.y, z + other.z));
}

Vector3& Vector3::operator-=(const Vector3& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

Vector3& Vector3::operator-(const Vector3& other) {
	return *(new Vector3(x - other.x, y - other.y, z - other.z));
}

Vector3& Vector3::operator*=(const float scalar)  {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}

Vector3& Vector3::operator*(const float scalar) {
	return *(new Vector3(x * scalar, y * scalar, z * scalar));
}

float Vector3::Dot(const Vector3& other) {
	return x * other.x + y * other.y + z * other.z;
}

void Vector3::Normalize() {
	float factor = (float) sqrt(x * x + y * y + z * z);
	x /= factor;
	y /= factor;
	z /= factor;
}

Vector3& Vector3::Normalized() {
	float factor = (float) sqrt(x * x + y * y + z * z);
	return *(new Vector3(x / factor, y / factor, z / factor));
}