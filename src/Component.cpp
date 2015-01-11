#include "Component.h"
#include "GameObject.h"

void Component::SetGameObject(GameObject *gameObject) {
	this->gameObject = gameObject;
}

GameObject* Component::GetGameObject()		{ return gameObject; }
Transform& Component::GetTransform() 		{ return gameObject->GetTransform(); }