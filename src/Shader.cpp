#include "Shader.h"

namespace util {
	std::string LoadFileText(const std::string& filePath) {
		std::ifstream file(filePath);

		std::string output;
		std::string line;

		if(file.is_open())
			while(file.good()) {
				std::getline(file, line);
				output.append(line + "\n");
			}

		return output;
	}

	static void CheckShaderError(int shader, int flag, bool isProgram, const std::string& errorMessage) {
		GLint success = 0;
		GLchar error[1024] = {0};

		if(isProgram)
			glGetProgramiv(shader, flag, &success);
		else
			glGetShaderiv(shader, flag, &success);

		if(!success) {
			if(isProgram)
				glGetProgramInfoLog(shader, sizeof(error), NULL, error);
			else
				glGetShaderInfoLog(shader, sizeof(error), NULL, error);

			fprintf(stderr, "%s: '%s'\n", errorMessage.c_str(), error);
		}
	}

	GLuint CreateShader(const std::string& text, GLenum type) {
		GLuint shader = glCreateShader(type);

		if(!shader)
			std::cerr << "Error: Shader creation failed: " << type << std::endl;

		const GLchar* source = text.c_str();
		const GLint length = text.length();

		glShaderSource(shader, 1, &source, &length);
		glCompileShader(shader);

		CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed");

		return shader;
	}
}

Shader::Shader(const std::string& filePath) {
	program = glCreateProgram();

	vertex = util::CreateShader(util::LoadFileText(filePath + ".vs"), GL_VERTEX_SHADER);
	fragment = util::CreateShader(util::LoadFileText(filePath + ".fs"), GL_FRAGMENT_SHADER);

	glAttachShader(program, vertex);
	glAttachShader(program, fragment);

	// this is not extremely necessary, but can prevent some weird bugs.
	glBindAttribLocation(program, 0, "position0");
	glBindAttribLocation(program, 1, "texCoord0");
	glBindAttribLocation(program, 2, "normal0");
	glBindAttribLocation(program, 3, "tangent0");

	glLinkProgram(program);
	util::CheckShaderError(program, GL_LINK_STATUS, true, "Error: Shader linking failed.");

	glValidateProgram(program);
	util::CheckShaderError(program, GL_VALIDATE_STATUS, true, "Error: Shader validation failed.");

	// get uniform locations.
	uniforms[U_TRANSFORM] = glGetUniformLocation(program, "u_transform");
	uniforms[U_MVP] = glGetUniformLocation(program, "u_mvp");
	uniforms[U_AMBIENT_LIGHT] = glGetUniformLocation(program, "u_ambientLight");
}

Shader::~Shader() {
	glDetachShader(program, vertex);
	glDeleteShader(vertex);

	glDetachShader(program, fragment);
	glDeleteShader(fragment);

	glDeleteProgram(program);
}

void Shader::Bind() {
	glUseProgram(program);
}

void Shader::Update(const Transform &transform, Material& material) {
	glm::mat4 model = transform.GetModel();
	material.GetTexture().Bind();

	glUniformMatrix4fv(uniforms[U_TRANSFORM], 1, GL_FALSE, &model[0][0]);
}

void Shader::SetUniform(GLint location, const glm::mat4 mvp) {
	glUniformMatrix4fv(uniforms[U_MVP], 1, GL_FALSE, &mvp[0][0]);
}

void Shader::SetUniform(GLint location, const glm::vec3 value) {
	glUniform3f(location, value.x, value.y, value.z);
}
