#include "Renderer.h"
#include "Display.h"

Camera* Renderer::camera = NULL;

void Renderer::Create() {
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.025, 0.35f, 1.0f);
}

void Renderer::Render(BaseGame *game) {
	// create a default camera if none is present.
	if(Renderer::camera == NULL)
		DefaultCamera();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shader.SetUniform(Shader::U_MVP, camera->GetMVP());
	shader.Bind();
	game->Render(shader);
}

void Renderer::SetCamera(Camera *camera) {
	Renderer::camera = camera;
}

void Renderer::DefaultCamera() {
	Renderer::camera = new Camera(0, Display::GetWidth(), 0, Display::GetHeight(), -1.0f, 1.0f);
}
