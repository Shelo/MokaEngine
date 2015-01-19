#ifndef BASE_LIGHT_H
#define BASE_LIGHT_H

#include "glm/vec3.hpp"
#include "Shader.h"
#include "Component.h"

class BaseLight {
private:
    glm::vec3 color;
    float intensity;

protected:
    Shader *shader;

public:
    BaseLight(const glm::vec3& color, float intensity) :
        color(color),
        intensity(intensity) {}

    virtual void Update() = 0;

    glm::vec3& GetColor() { return color; }
    float GetIntensity() { return intensity; }
    Shader* GetShader() { return shader; }

    void SetShader(Shader* shader) { this->shader = shader; }
    void SetColor(const glm::vec3& color) { this->color = color; }
    void SetIntensity(float intensity) { this->intensity = intensity; }
};

#endif