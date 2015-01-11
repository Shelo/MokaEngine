#include "Camera.h"
#include "Renderer.h"

void Camera::SetCurrent() {
    Renderer::SetCamera(this);
}
