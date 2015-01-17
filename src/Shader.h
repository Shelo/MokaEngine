#ifndef SHADER_H
#define SHADER_H

#include <fstream>
#include <string>
#include <iostream>
#define GLEW_STATIC
#include "GL/glew.h"
#include "Transform.h"
#include "Material.h"

class Shader {
public:
	Shader(const std::string& filePath);
	virtual ~Shader();

	void Bind();
	void Update(const Transform& transform, Material& material);

	void SetUniform(GLint location, const glm::mat4 mvp);
	void SetUniform(GLint location, const glm::vec3 value);

	enum {
		U_TRANSFORM,
		U_MVP,
		U_AMBIENT_LIGHT,

		UNIFORMS_SIZE
	};

	GLint uniforms[UNIFORMS_SIZE];
private:
	GLuint fragment;
	GLuint program;
	GLuint vertex;
};

#endif