#ifndef SHADER_H
#define SHADER_H

#include <fstream>
#include <string>
#include <iostream>
#include "GL/glew.h"
#include "Transform.h"

class Shader {
public:
	Shader(const std::string& filePath);
	virtual ~Shader();

	void Bind();
	void Update(const Transform *transform);

private:
	GLuint fragment;
	GLuint program;
	GLuint vertex;
	
	enum {
		U_TRANSFORM,

		NUM_UNIFORMS
	};

	GLuint uniforms[NUM_UNIFORMS];
};

#endif