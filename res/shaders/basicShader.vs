#version 330

layout (location = 0) in vec3 position0;
layout (location = 1) in vec2 texCoord0;
layout (location = 2) in vec3 normal0;
layout (location = 3) in vec3 tangent0;

uniform mat4 u_transform;
uniform mat4 u_mvp;

out vec2 v_texCoord;
out vec3 v_normal;

void main() {
	v_texCoord = texCoord0;
	v_normal = (u_transform * vec4(normal0, 0)).xyz;

	gl_Position = u_mvp * u_transform * vec4(position0, 1.0);
}
