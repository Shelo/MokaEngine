#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Component.h"
#include "Transform.h"
#include <vector>

class GameObject {
public:
	GameObject(float x, float y);
	~GameObject();
	GameObject* AddComponent(Component *component);
	GameObject* AddChild(GameObject *gameObject);

	int GetChildCount();
	Transform* GetTransform();

	void Create();
	void Update();
	void Render();
private:
	std::vector<GameObject*> children;
	std::vector<Component*> components;
	Transform *transform;
};

#endif