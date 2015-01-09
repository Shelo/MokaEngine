#ifndef BASEGAME_H
#define BASEGAME_H

#include "GameObject.h"

class BaseGame {
private:
	GameObject *root;
public:
	BaseGame();
	~BaseGame();

	virtual void Create() = 0;

	virtual void Create2() final;
	virtual void Update() final;
	virtual void Render() final;

	void AddGameObject(GameObject *child);
	void AddComponent(Component *component);
};

#endif