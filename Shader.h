#ifndef SHADER_H
#define SHADER_H

#include <fstream>
#include <string>
#include <iostream>
#include "GL/glew.h"

class Shader {
public:
	Shader(const std::string& filePath);
	virtual ~Shader();

	void Bind();
private:
	GLuint fragment;
	GLuint program;
	GLuint vertex;
};

#endif