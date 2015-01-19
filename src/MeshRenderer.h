#ifndef MESH_RENDERER_H
#define MESH_RENDERER_H

#include "Mesh.h"
#include "Material.h"
#include "Component.h"

class MeshRenderer : public Component {
private:
    Material material;
    Mesh mesh;
public:
    MeshRenderer(const Mesh& mesh, const Material& material) :
        material(material),
        mesh(mesh) {}

    void Render(Shader& shader);

    inline Mesh& GetMesh() { return mesh; }
    inline Material& GetMaterial() { return material; }
};

#endif