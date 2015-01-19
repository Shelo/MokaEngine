#ifndef RENDERER_H
#define RENDERER_H

#include "light/BaseLight.h"
#include "Shader.h"
#include "BaseGame.h"
#include "Camera.h"

class Renderer {
private:
	static Camera *camera;

	Shader ambientShader;
	Shader directionalShader;
	std::vector<BaseLight*> lights;

	void DefaultCamera();

public:
	Renderer() :
		ambientShader("ambient"),
		directionalShader("directional") {}

	void Create();
	void Render(BaseGame *game);

	void AddLight(BaseLight* light, unsigned int type);

	Shader& GetShader() { return ambientShader; }
	static void SetCamera(Camera *camera);

	enum {
		SHADER_DIRECTIONAL,
	};
};

#endif