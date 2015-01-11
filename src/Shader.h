#ifndef SHADER_H
#define SHADER_H

#include <fstream>
#include <string>
#include <iostream>
#define GLEW_STATIC
#include "GL/glew.h"
#include "Transform.h"

class Shader {
public:
	Shader(const std::string& filePath);
	virtual ~Shader();

	void Bind();
	void Update(const Transform &transform);


	void SetUniform(GLint location, const glm::mat4 mvp);

	enum {
		U_TRANSFORM,
		U_MVP,

		NUM_UNIFORMS
	};

private:
	GLuint fragment;
	GLuint program;
	GLuint vertex;

	GLint uniforms[NUM_UNIFORMS];
};

#endif