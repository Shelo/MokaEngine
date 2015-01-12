#ifndef CAMERA_H
#define CAMERA_H

#include <glm/gtc/matrix_transform.hpp>
#include "Component.h"

class Camera : public Component {
private:
    glm::mat4 projection;
    bool perspective;
public:
    Camera(float fov, float aspect, float zNear, float zFar) :
        projection(glm::perspective(fov, aspect, zNear, zFar)),
        perspective(true) {}

    Camera(float left, float right, float bottom, float top, float zNear, float zFar) :
        projection(glm::ortho(left, right, bottom, top, zNear, zFar)),
        perspective(false) {}

    glm::mat4 GetMVP();
    void SetCurrent();
};

#endif
