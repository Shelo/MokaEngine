#include "Transform.h"

Transform::Transform(glm::vec3 *position, glm::vec3 *scale, glm::fquat *rotation) {
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
}

Transform::Transform(float x, float y, float z) {
	position = new glm::vec3(x, y, z);
	rotation = new glm::fquat();
	scale = new glm::vec3();
}

Transform::Transform(float x, float y) : Transform(x, y, 0) {}

Transform::~Transform() {
	delete position;
	delete rotation;
	delete scale;
}

glm::vec3* Transform::GetPosition() {
	return position;
}

glm::fquat* Transform::GetRotation() {
	return rotation;
}

glm::vec3* Transform::GetScale() {
	return scale;
}
