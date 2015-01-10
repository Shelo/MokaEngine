#include "Component.h"
#include "GameObject.h"

Component::Component() {

}

Component::~Component() {

}

void Component::SetGameObject(GameObject *gameObject) {
	this->gameObject = gameObject;
}

Transform* Component::GetTransform() {
	return gameObject->GetTransform();
}

GameObject* Component::GetGameObject() {
	return gameObject;
}
