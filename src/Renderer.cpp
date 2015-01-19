#include "Renderer.h"
#include "Display.h"
#include "Moka.h"
#include "light/BaseLight.h"

Camera* Renderer::camera = NULL;

void Renderer::Create() {
	Moka::Create(this);

	glFrontFace(GL_CW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.025, 0.35f, 1.0f);

	ambientShader.Bind();
}

void Renderer::Render(BaseGame *game) {
	// create a default camera if none is present.
	if(Renderer::camera == NULL)
		DefaultCamera();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	ambientShader.Bind();
	ambientShader.SetUniform("u_mvp", camera->GetMVP());
	ambientShader.SetUniform("u_eyePos", camera->GetTransform().GetPosition());

	directionalShader.Bind();
	directionalShader.SetUniform("u_mvp", camera->GetMVP());
	directionalShader.SetUniform("u_eyePos", camera->GetTransform().GetPosition());

	ambientShader.Bind();
	game->Render(ambientShader);

	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);
	glDepthMask(GL_FALSE);
	glDepthFunc(GL_EQUAL);

	for(int i = 0; i < lights.size(); ++i) {
		lights[i]->Update();
		game->Render(*lights[i]->GetShader());
	}

	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LESS);
	glDisable(GL_BLEND);
}

void Renderer::SetCamera(Camera *camera) {
	Renderer::camera = camera;
}

void Renderer::DefaultCamera() {
	Renderer::camera = new Camera(0, Display::GetWidth(), 0, Display::GetHeight(), -1.0f, 1.0f);
}

void Renderer::AddLight(BaseLight *light, unsigned int type) {
	switch(type) {
		case SHADER_DIRECTIONAL:
			light->SetShader(&directionalShader);
			break;
		default:
			std::cerr << "Shader not available" << std::endl;
	}

	lights.push_back(light);
}
