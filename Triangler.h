#ifndef TRIANGLER_H
#define TRIANGLER_H

#include "Component.h"
#include "Vertex.h"
#include "Mesh.h"
#include "HeapArray.h"
#include <iostream>

class Triangler : public Component {
private:
	Mesh *mesh;
public:
	Triangler() {}
	virtual ~Triangler();

	void Create();
	void Render();
};

#endif