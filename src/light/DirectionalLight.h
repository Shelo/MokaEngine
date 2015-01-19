#ifndef DIRECTIONAL_LIGHT_H
#define DIRECTIONAL_LIGHT_H

#include <Moka.h>
#include "BaseLight.h"

class DirectionalLight : public BaseLight, public Component {
private:
    glm::vec3 direction;

public:
    DirectionalLight(const glm::vec3& color, float intensity, const glm::vec3& direction) :
        BaseLight(color, intensity),
        direction(direction) {}

    virtual void Create();
    virtual void Update();

    glm::vec3& GetDirection() { return direction; }
};

#endif