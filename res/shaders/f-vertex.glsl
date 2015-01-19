#version 330

layout (location = 0) in vec3 position0;
layout (location = 1) in vec2 texCoord0;
layout (location = 2) in vec3 normal0;
layout (location = 3) in vec3 tangent0;

uniform mat4 u_model;
uniform mat4 u_mvp;
uniform vec2 u_tiling;

out vec2 v_texCoord;
out vec3 v_worldPos;
out vec3 v_normal;
out mat3 v_tbnMat;

void main() {
	v_worldPos 	= (u_model * vec4(position0, 1.0)).xyz;
	v_normal 	= normalize(u_model * vec4(normal0, 0)).xyz;
	v_texCoord 	= texCoord0 * u_tiling;

	// calc tangent rotation matrix.
    vec3 t = normalize((u_model * vec4(tangent0, 0.0)).xyz);
    t = normalize(t - dot(t, v_normal) * v_normal);
    vec3 biTangent = cross(t, v_normal);
    v_tbnMat = mat3(t, biTangent, v_normal);

	gl_Position = u_mvp * u_model * vec4(position0, 1.0);
}
