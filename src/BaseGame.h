#ifndef BASEGAME_H
#define BASEGAME_H

#include "GameObject.h"
#include "Shader.h"

class BaseGame {
private:
	GameObject root;
public:
	BaseGame() :
			root(0, 0) {}

	virtual void Create() = 0;

	virtual void ICreate() final;
	virtual void Update(double delta) final;
	virtual void Render(Shader &shader) final;

	void AddGameObject(GameObject *child);
	void AddComponent(Component *component);
};

#endif