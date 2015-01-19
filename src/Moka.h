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
        renderer->GetShader().SetUniform("u_ambientLight", glm::vec3(r, g, b));
    }

    static void SetClearColor(int r, int g, int b) {
        glClearColor(r, g, b, 1);
    }

    static void AddLight(BaseLight* light, unsigned int type) {
        renderer->AddLight(light, type);
    }
};

#endif