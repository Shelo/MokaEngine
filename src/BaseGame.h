#ifndef BASEGAME_H
#define BASEGAME_H

#include "GameObject.h"
#include "Shader.h"

class BaseGame {
private:
	GameObject *root;
public:
	BaseGame();
	~BaseGame();

	virtual void Create() = 0;

	virtual void ICreate() final;
	virtual void Update() final;
	virtual void Render(Shader *shader) final;

	void AddGameObject(GameObject *child);
	void AddComponent(Component *component);
};

#endif