#ifndef SHADER_H
#define SHADER_H

#include <fstream>
#include <string>
#include <iostream>
#include <map>

#define GLEW_STATIC
#include "GL/glew.h"
#include "Transform.h"
#include "Material.h"

class Shader {
public:
	Shader(const std::string&name);
	virtual ~Shader();

	void Bind();
	void Update(const Transform& transform, Material& material);

	/**
	 * Returns an stored location for an existing uniform, if the location isn't found, this method
	 * creates one.
	 */
	GLint GetUniformLocation(const std::string& uniform);

	void SetUniform(std::string uniform, const glm::mat4 values);
	void SetUniform(std::string uniform, const glm::vec3 value);
	void SetUniform(std::string uniform, const glm::vec4 value);
	void SetUniform(std::string uniform, const float value);
	void SetUniform(std::string uniform, const int value);
	void SetUniform(std::string uniform, const float x, const float y);

private:
	// map for uniform's locations.
	std::map<std::string, GLint> uniforms;

	// program pointer.
	GLuint program;

	// shader pointers.
	GLuint fragment;
	GLuint vertex;

	Texture defaultNormalMap;
};

#endif