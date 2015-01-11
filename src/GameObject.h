#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Component.h"
#include <vector>

class GameObject {
private:
	std::vector<Component*> components;
	std::vector<GameObject*> children;
	Transform transform;
public:
	GameObject(float x, float y) :
			transform(x, y, 0) {}

	GameObject() :
			transform(0, 0, 0) {}

	virtual ~GameObject();

	GameObject* AddComponent(Component *component);
	GameObject* AddChild(GameObject *gameObject);

	int GetChildCount();
	Transform& GetTransform() { return transform; }

	void Create();
	void Update();
	void Render(Shader *shader);
};

#endif