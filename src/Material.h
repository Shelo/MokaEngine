#ifndef MATERIAL_H
#define MATERIAL_H

#include <glm/vec3.hpp>
#include "Texture.h"

class Material {
private:
    Texture *normalMap;
    Texture *texture;
    glm::vec3 color;

    float specIntensity;
    float specExponent;

    float tilingX;
    float tilingY;
public:
    Material(Texture *_texture, const glm::vec3& color) :
        normalMap(NULL),
        texture(_texture),
        color(color),
        specIntensity(0),
        specExponent(0),
        tilingX(1.0f),
        tilingY(1.0f) {}

    virtual ~Material();

    void SetSpecular(float specIntensity, float specExponent) {
        this->specIntensity = specIntensity;
        this->specExponent  = specExponent;
    }

    void SetTiling(float tilingX, float tilingY) {
        this->tilingX = tilingX;
        this->tilingY = tilingY;
    }

    void SetNormalMap(Texture* normalMap) {
        this->normalMap = normalMap;
    }

    Texture& GetTexture() { return *texture; }
    glm::vec3& GetColor() { return color; }
    float GetSpecularIntensity() { return specIntensity; }
    float GetSpecularExponent() { return specExponent; }
    float GetTilingX() { return tilingX; }
    float GetTilingY() { return tilingY; }
    Texture& GetNormalMap() { return *normalMap; }
    bool HasNormalMap() { return normalMap != NULL; }
};

#endif