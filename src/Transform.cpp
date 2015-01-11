#include "Transform.h"

glm::mat4 Transform::GetModel() const {
	glm::mat4 _position = glm::translate(position);
	glm::mat4 _scale = glm::scale(scale);
	
	glm::mat4 _rotx = glm::rotate(rotation.x, glm::vec3(1, 0, 0));
	glm::mat4 _roty = glm::rotate(rotation.y, glm::vec3(0, 1, 0));
	glm::mat4 _rotz = glm::rotate(rotation.z, glm::vec3(0, 0, 1));

	glm::mat4 _rotation = _rotz * _roty * _rotx;
	
	glm::mat4 model = _position * _rotation * _scale;
	return model;
}
