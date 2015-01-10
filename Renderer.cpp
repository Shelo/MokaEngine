#include "Renderer.h"


Renderer::Renderer() {
	shader = new Shader("./res/shaders/basicShader");
}

void Renderer::Render() {
	shader->Bind();
}

Renderer::~Renderer() {
	delete shader;
}
