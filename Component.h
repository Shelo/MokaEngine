#ifndef COMPONENT_H
#define COMPONENT_H

#include "Transform.h"

class Component {
public:
	Component();
	~Component();

	virtual void Create() {}
	virtual void Update() {}
	virtual void Render() {}

private:
	Transform *transform;

	Transform& getTransform();
	Transform& getGameObject();
};

#endif