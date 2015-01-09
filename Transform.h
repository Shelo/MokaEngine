#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "glm/vec3.hpp"
#include "glm/gtc/quaternion.hpp"

class Transform {
private:
	glm::fquat *rotation;
	glm::vec3 *position;
	glm::vec3 *scale;
public:
	Transform(glm::vec3 *position, glm::vec3 *scale, glm::fquat *rotation);

	Transform(float x, float y, float z);
	Transform(float x, float y);

	glm::vec3* GetPosition();
	glm::fquat* GetRotation();
	glm::vec3* GetScale();

	~Transform();
};

#endif