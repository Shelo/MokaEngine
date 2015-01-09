#include "Util.h"

namespace util {
	GLfloat* GenArray(util::HeapArray<Vertex*> &vertices) {
		GLfloat *vdata = new GLfloat[vertices.Size() * Vertex::SIZE];

		for(size_t i = 0; i < vertices.Size(); i++) {
			int offset = i * Vertex::SIZE;
		}

		return vdata;
	}
}
