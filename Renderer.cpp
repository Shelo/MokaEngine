#include "Renderer.h"

Renderer::Renderer() {
	shader = new Shader("./res/shaders/basicShader");
}

Renderer::~Renderer() {
	delete shader;
}

void Renderer::Create() {
	glFrontFace(GL_CW);
	glCullFace(GL_CCW);
	glClearColor(0.0f, 0.025, 0.35f, 1.0f);
}

void Renderer::Render(BaseGame *game) {
	glClear(GL_COLOR_BUFFER_BIT);
	shader->Bind();
	game->Render(shader);
}

Shader* Renderer::GetShader() {
	return shader;
}
