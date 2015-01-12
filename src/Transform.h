#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/quaternion.hpp"

class Transform {
private:
	glm::vec3 rotation;
	glm::vec3 position;
	glm::vec3 scale;
public:
	Transform(glm::vec3& _position, glm::vec3& _scale, glm::vec3& _rotation) :
		position(_position),
		scale(_scale),
		rotation(_rotation) {}

	Transform(float x, float y, float z) :
		position(x, y, z),
		scale(1, 1, 1),
		rotation(0, 0, 0) {}

	glm::mat4 GetModel() const;

	inline glm::vec3& GetPosition()	 { return position; }
	inline glm::vec3& GetRotation()	 { return rotation; }
	inline glm::vec3& GetScale()	 { return scale; }

	inline void SetScale(float x, float y, float z) {
		scale.x = x;
		scale.y = y;
		scale.z = z;
	}
};

#endif