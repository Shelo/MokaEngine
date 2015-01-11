#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#define GLEW_STATIC
#include "GL/glew.h"
#include <iostream>
#include <cassert>

class Texture {
public:
	Texture(const std::string& filePath);

	void Bind();
	void Bind(GLuint unit);

	virtual ~Texture();
private:
	GLuint texture;
};

#endif