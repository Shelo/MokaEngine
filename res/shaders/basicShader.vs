#version 330

layout (location = 0) in vec3 position0;
layout (location = 1) in vec2 texCoord0;

out vec2 texCoord;

void main() {
	texCoord = texCoord0;
	gl_Position = vec4(position0, 1);
}
