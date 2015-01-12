#include "Transform.h"

glm::mat4 Transform::GetModel() const {
	glm::mat4 _position = glm::translate(position);
	glm::mat4 _scale = glm::scale(scale);
	glm::mat4 _rotation = glm::mat4_cast(rotation);

	return _position * _rotation * _scale;
}
