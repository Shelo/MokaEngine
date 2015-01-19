#include "DirectionalLight.h"

void DirectionalLight::Update() {
    shader->Bind();
    shader->SetUniform("u_directionalLight.direction", GetDirection());
    shader->SetUniform("u_directionalLight.base.color", GetColor());
    shader->SetUniform("u_directionalLight.base.intensity", GetIntensity());
}

void DirectionalLight::Create() {
    Moka::AddLight((BaseLight*) this, Renderer::SHADER_DIRECTIONAL);
}
