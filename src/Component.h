#ifndef COMPONENT_H
#define COMPONENT_H

class GameObject;
#include "Shader.h"

class Component {
public:
	virtual void Create() {}
	virtual void Update() {}
	virtual void Render(Shader *shader) {}

	void SetGameObject(GameObject *gameObject);

	GameObject* GetGameObject();
	Transform& GetTransform();

private:
	GameObject *gameObject;
};

#endif