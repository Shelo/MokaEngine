#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/quaternion.hpp"

class Transform {
private:
	glm::vec3 *rotation;
	glm::vec3 *position;
	glm::vec3 *scale;
public:
	Transform(glm::vec3 *position, glm::vec3 *scale, glm::vec3 *rotation);
	
	Transform(float x, float y, float z);
	Transform(float x, float y);

	glm::mat4 GetModel() const;

	glm::vec3* GetPosition();
	glm::vec3* GetRotation();
	glm::vec3* GetScale();

	~Transform();
};

#endif