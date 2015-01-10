#include "Transform.h"

Transform::Transform(glm::vec3 *position, glm::vec3 *scale, glm::vec3 *rotation) {
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
}

Transform::Transform(float x, float y, float z) {
	position = new glm::vec3(x, y, z);
	rotation = new glm::vec3(0.0f, 0.0f, 0.0f);
	scale = new glm::vec3(1.0f, 1.0f, 1.0f);
}

Transform::Transform(float x, float y) : Transform(x, y, 0) {}

Transform::~Transform() {
	delete position;
	delete rotation;
	delete scale;
}

glm::mat4 Transform::GetModel() const {
	glm::mat4 _position = glm::translate(*position);
	glm::mat4 _scale = glm::scale(*scale);
	
	glm::mat4 _rotx = glm::rotate(rotation->x, glm::vec3(1, 0, 0));
	glm::mat4 _roty = glm::rotate(rotation->y, glm::vec3(0, 1, 0));
	glm::mat4 _rotz = glm::rotate(rotation->z, glm::vec3(0, 0, 1));

	glm::mat4 _rotation = _rotz * _roty * _rotx;
	
	glm::mat4 model = _position * _rotation * _scale;
	return model;
}

glm::vec3* Transform::GetPosition() {
	return position;
}

glm::vec3* Transform::GetRotation() {
	return rotation;
}

glm::vec3* Transform::GetScale() {
	return scale;
}
