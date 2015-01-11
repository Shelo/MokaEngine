#version 330

layout (location = 0) in vec3 position0;
layout (location = 1) in vec2 texCoord0;

uniform mat4 u_transform;
uniform mat4 u_mvp;

out vec2 texCoord;

void main() {
	texCoord = texCoord0;
	gl_Position = u_transform * vec4(position0, 1.0);
}
