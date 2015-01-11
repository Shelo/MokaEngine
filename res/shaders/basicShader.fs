#version 330

uniform sampler2D u_texture;

in vec2 texCoord;

void main() {
	gl_FragColor = texture(u_texture, texCoord) * vec4(1, 1, 1, 1); 
}
