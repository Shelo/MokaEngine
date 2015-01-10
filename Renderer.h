#ifndef RENDERER_H
#define RENDERER_H

#include "Shader.h"

class Renderer {
private:
	Shader *shader;
public:
	Renderer();
	~Renderer();
	void Render();
};

#endif