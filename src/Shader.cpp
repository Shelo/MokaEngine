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

	static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage) {
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

Shader::Shader(const std::string& name) :
	defaultNormalMap("res/textures/default_normal.jpg") {

	program = glCreateProgram();

	vertex = util::CreateShader(util::LoadFileText("res/shaders/f-vertex.glsl"), GL_VERTEX_SHADER);
	fragment = util::CreateShader(util::LoadFileText("res/shaders/f-frag-" + name + ".glsl"), GL_FRAGMENT_SHADER);

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

	SetUniform("u_normalMap", 1);

	if(material.HasNormalMap())
		material.GetNormalMap().Bind(1);
	else
		defaultNormalMap.Bind(1);

	SetUniform("u_model", model);
	SetUniform("u_color", material.GetColor());
	SetUniform("u_specularIntensity", material.GetSpecularIntensity());
	SetUniform("u_specularExponent", material.GetSpecularExponent());
	SetUniform("u_tiling", material.GetTilingX(), material.GetTilingY());
}

void Shader::SetUniform(std::string uniform, const glm::mat4 values) {
	glUniformMatrix4fv(GetUniformLocation(uniform), 1, GL_FALSE, &values[0][0]);
}

void Shader::SetUniform(std::string uniform, const glm::vec3 value) {
	glUniform3f(GetUniformLocation(uniform), value.x, value.y, value.z);
}

void Shader::SetUniform(std::string uniform, const glm::vec4 value) {
	glUniform4f(GetUniformLocation(uniform), value.x, value.y, value.z, value.w);
}

void Shader::SetUniform(std::string uniform, const int value) {
	glUniform1i(GetUniformLocation(uniform), value);
}

void Shader::SetUniform(std::string uniform, const float value) {
	glUniform1f(GetUniformLocation(uniform), value);
}

void Shader::SetUniform(std::string uniform, const float x, const float y) {
	glUniform2f(GetUniformLocation(uniform), x, y);
}

GLint Shader::GetUniformLocation(const std::string& uniform) {
	std::map<std::string, GLint>::iterator it = uniforms.find(uniform);

	GLint location = 0;
	if(it != uniforms.end())
		location = it->second;
	else {
		location = glGetUniformLocation(program, uniform.c_str());

		if(location == -1)
			std::cerr << "[Ignore] No uniform with name: " << uniform << std::endl;

		uniforms[uniform] = location;
	}


	return location;
}
