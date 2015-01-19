#version 330

// Samplers.
uniform sampler2D u_texture;
uniform sampler2D u_normalMap;

// Light Uniforms.
uniform vec3 u_ambientLight;

// Material.
uniform vec3 u_color;

// Varyings.
in vec2 v_texCoord;
in vec3 v_worldPos;
in vec3 v_normal;
in mat3 v_tbnMat;

void main() {
	vec4 texColor 	= texture2D(u_texture, v_texCoord);
	vec4 color 		= vec4(u_color, 1);

	if(texColor != vec4(0, 0, 0, 0))
		color *= texColor;

	gl_FragColor = color * vec4(u_ambientLight, 1);
}
