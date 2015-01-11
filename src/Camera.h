#ifndef CAMERA_H
#define CAMERA_H

#include <glm/gtc/matrix_transform.hpp>
#include "Component.h"

class Camera : public Component {
private:
    glm::mat4 projection;
    glm::vec3 forward;
    bool perspective;
    glm::vec3 up;
public:
    Camera(float fov, float aspect, float zNear, float zFar) :
        projection(glm::perspective(fov, aspect, zNear, zFar)),
        forward(0.0f, 0.0f, 1.0f),
        up(0.0f, 1.0f, 0.0f),
        perspective(true)
    {}

    Camera(float left, float right, float bottom, float top, float zNear, float zFar) :
        projection(glm::ortho(left, right, bottom, top, zNear, zFar)),
        forward(0.0f, 0.0f, 1.0f),
        up(0.0f, 1.0f, 0.0f),
        perspective(false)
    {}

    inline glm::mat4 GetMVP() {
        if(perspective)
            return projection *
                    glm::lookAt(GetTransform().GetPosition() * -1.0f, GetTransform().GetPosition() + forward, up);
        else
            return projection;
    }

    void SetCurrent();
};

#endif
