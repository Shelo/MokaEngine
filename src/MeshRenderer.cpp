#include "MeshRenderer.h"

void MeshRenderer::Render(Shader &shader) {
    shader.Update(GetTransform(), material);
    mesh.Draw();
}
