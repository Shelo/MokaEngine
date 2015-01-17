#version 330

// Samplers.
uniform sampler2D u_texture;

// Light Uniforms.
uniform vec3 u_ambientLight;

// Structs.
struct BaseLight {
	vec3 color;
	float intensity;
};

struct DirectionalLight {
	BaseLight base;
	vec3 direction;
};

// Varyings.
in vec2 v_texCoord;
in vec3 v_normal;

void main() {
	vec4 texColor 	= texture2D(u_texture, v_texCoord);
	vec4 totalLight = vec4(u_ambientLight, 1);
	vec4 color 		= vec4(1, 1, 1, 1);

	if(texColor != vec4(0, 0, 0, 0))
		color *= texColor;

	vec3 normal = normalize(v_normal);
//	totalLight += calcDirectionalLight(directionalLight, normal);

	gl_FragColor = color * totalLight; 
}
