#ifndef BASEGAME_H
#define BASEGAME_H

class BaseGame {
public:
	BaseGame();
	~BaseGame();
	virtual void Create() = 0;
};

#endif