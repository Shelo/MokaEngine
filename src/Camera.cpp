#include "Camera.h"
#include "Renderer.h"

void Camera::SetCurrent() {
    Renderer::SetCamera(this);
}

glm::mat4 Camera::GetMVP() {
    glm::vec3 pos = GetTransform().GetPosition();
    pos.z *= -1.0f;

    glm::mat4 _translation = glm::translate(pos);
    glm::mat4 _rotation = glm::mat4_cast(glm::conjugate(GetTransform().GetRotation()));

    if(perspective)
        return projection * _rotation * _translation;
    else
        return projection;
}
