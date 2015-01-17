#ifndef MOKA_H
#define MOKA_H

#include "glm/vec3.hpp"
#include "Renderer.h"

class Moka {
private:
    static Renderer* renderer;
public:
    static void Create(Renderer* renderer) {
        Moka::renderer = renderer;
    }

    static void SetAmbientLight(float r, float g, float b) {
        renderer->GetShader().SetUniform(Shader::U_AMBIENT_LIGHT, glm::vec3(r, g, b));
    }
};

#endif