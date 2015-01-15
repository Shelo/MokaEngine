#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <iostream>
#include "glm/glm.hpp"
#include "glm/gtx/quaternion.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/quaternion.hpp"

class Transform {
private:
	glm::quat rotation;
	glm::vec3 position;
	glm::vec3 scale;
public:
	Transform(glm::vec3& _position, glm::vec3& _scale, glm::quat& _rotation) :
		position(_position),
		scale(_scale),
		rotation(_rotation) {}

	Transform(float x, float y, float z) :
		position(x, y, z),
		scale(1, 1, 1),
		rotation(1, 0, 0, 0) {}

	glm::mat4 GetModel() const;

	inline glm::vec3& GetPosition()	 { return position; }
	inline glm::quat& GetRotation()	 { return rotation; }
	inline glm::vec3& GetScale()	 { return scale; }

	void Move(const glm::vec3 dir, const float amount) {
		position += dir * amount;
	}

	inline void SetScale(float x, float y, float z) {
		scale.x = x;
		scale.y = y;
		scale.z = z;
	}

	inline void Rotate(const glm::vec3 axis, const float radians) {
		GetRotation() = glm::normalize(glm::angleAxis(radians, axis) * GetRotation());
	}

	inline glm::vec3 GetRight() {
		return glm::rotate(GetRotation(), glm::vec3(1.0f, 0.0f, 0.0f));
	}

	inline glm::vec3 GetLeft() {
		return glm::rotate(GetRotation(), glm::vec3(-1.0f, 0.0f, 0.0f));
	}

	inline glm::vec3 GetForward() {
		return glm::rotate(GetRotation(), glm::vec3(0.0f, 0.0f, -1.0f));
	}

	inline glm::vec3 GetBack() {
		return glm::rotate(GetRotation(), glm::vec3(0.0f, 0.0f, 1.0f));
	}

	inline glm::vec3 GetUp() {
		return glm::rotate(GetRotation(), glm::vec3(0.0f, 1.0f, 0.0f));
	}

	inline glm::vec3 GetDown() {
		return glm::rotate(GetRotation(), glm::vec3(0.0f, -1.0f, 0.0f));
	}
};

#endif