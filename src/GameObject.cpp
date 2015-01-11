#include "GameObject.h"
#include <iostream>

GameObject::~GameObject() {
	for(size_t i = 0; i < components.size(); i++)
		delete components[i];

	for(size_t i = 0; i < children.size(); i++)
		delete children[i];

	components.clear();
	children.clear();
}

GameObject* GameObject::AddChild(GameObject *gameObject) {
	children.push_back(gameObject);
	return this;
}

GameObject* GameObject::AddComponent(Component *component) {
	component->SetGameObject(this);
	components.push_back(component);
	return this;
}

int GameObject::GetChildCount() {
	return children.size();
}

void GameObject::Create() {
	for(size_t i = 0; i < components.size(); i++)
		components[i]->Create();

	for(size_t i = 0; i < children.size(); i++)
		children[i]->Create();
}

void GameObject::Update() {
	for(size_t i = 0; i < components.size(); i++)
		components[i]->Update();

	for(size_t i = 0; i < children.size(); i++)
		children[i]->Update();
}

void GameObject::Render(Shader &shader) {
	for(size_t i = 0; i < components.size(); i++)
		components[i]->Render(shader);

	for(size_t i = 0; i < children.size(); i++)
		children[i]->Render(shader);
}