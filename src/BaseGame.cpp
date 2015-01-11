#include "BaseGame.h"
#include <iostream>

void BaseGame::AddGameObject(GameObject *child) {
	root.AddChild(child);
}

void BaseGame::ICreate() {
	root.Create();
}

void BaseGame::Update() {
	root.Update();
}

void BaseGame::Render(Shader &shader) {
	root.Render(shader);
}

void BaseGame::AddComponent(Component *component) {
	root.AddComponent(component);
}