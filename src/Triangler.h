#ifndef TRIANGLER_H
#define TRIANGLER_H

#include "HeapArray.h"
#include "Component.h"
#include "Vertex.h"
#include "Mesh.h"

class Triangler : public Component {
private:
	Mesh *mesh;
public:
	Triangler() {}
	virtual ~Triangler();

	void Create();
	void Render(Shader &shader);
};

#endif