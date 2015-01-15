#ifndef MATERIAL_H
#define MATERIAL_H

#include <glm/detail/type_vec.hpp>
#include <glm/detail/type_vec4.hpp>
#include "Texture.h"

class Material {
private:
    Texture *texture;
    glm::vec4 color;
public:
    Material(Texture *_texture, float r, float g, float b, float a) :
        texture(_texture),
        color(r, g, b, a) {}

    virtual ~Material();

    Texture& GetTexture() { return *texture; }
};

#endif