#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Component.h"
#include <vector>

class GameObject {
public:
	GameObject(float x, float y);
	virtual ~GameObject();

	GameObject* AddComponent(Component *component);
	GameObject* AddChild(GameObject *gameObject);

	int GetChildCount();
	Transform* GetTransform();

	void Create();
	void Update();
	void Render(Shader *shader);
private:
	std::vector<Component*> components;
	std::vector<GameObject*> children;
	Transform *transform;
};

#endif