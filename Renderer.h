#ifndef RENDERER_H
#define RENDERER_H

#include "Shader.h"
#include "BaseGame.h"

class Renderer {
private:
	Shader *shader;
public:
	Renderer();
	~Renderer();

	void Create();
	void Render(BaseGame *game);

	Shader* GetShader();
};

#endif