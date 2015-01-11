#ifndef RENDERER_H
#define RENDERER_H

#include "Shader.h"
#include "BaseGame.h"
#include "Camera.h"

class Renderer {
private:
	Shader shader;
	static Camera *camera;

	void DefaultCamera();

public:
	Renderer() :
		shader("res/shaders/basicShader") {}

	void Create();
	void Render(BaseGame *game);

	Shader& GetShader() { return shader; }

	static void SetCamera(Camera *camera);
};

#endif