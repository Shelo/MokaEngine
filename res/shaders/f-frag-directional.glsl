#version 330

// Structs.
struct BaseLight {
	vec3 color;
	float intensity;
};

struct DirectionalLight {
	BaseLight base;
	vec3 direction;
};

// Samplers.
uniform sampler2D u_texture;
uniform sampler2D u_normalMap;

// Material Uniforms.
uniform float u_specularIntensity;
uniform float u_specularExponent;
uniform vec3 u_color;

// World Uniforms.
uniform DirectionalLight u_directionalLight;
uniform vec3 u_eyePos;

// Varyings.
in vec2 v_texCoord;
in vec3 v_normal;
in vec3 v_worldPos;
in mat3 v_tbnMat;

vec4 calcLight(BaseLight base, vec3 direction, vec3 normal) {
	float diffuseFactor = dot(normal, - direction);
	vec4 specularColor 	= vec4(0, 0, 0, 0);
	vec4 diffuseColor 	= vec4(0, 0, 0, 0);

	if(diffuseFactor > 0) {
		diffuseColor = vec4(base.color, 1.0) * base.intensity * diffuseFactor;

		vec3 directionToEye = normalize(u_eyePos - v_worldPos);
		vec3 reflectDirection = normalize(reflect(direction, normal));

		float specularFactor = dot(directionToEye, reflectDirection);
		specularFactor = pow(specularFactor, u_specularExponent);

		if(specularFactor > 0)
			specularColor = vec4(base.color, 1.0) * u_specularIntensity * specularFactor;
	}

	return diffuseColor + specularColor;
}

vec4 calcDirectionalLight(DirectionalLight light, vec3 normal) {
	return calcLight(light.base, light.direction, normal);
}

void main() {
	vec3 normal = normalize(v_tbnMat * (255.0/128.0 * texture2D(u_normalMap, v_texCoord).xyz - 1));
	gl_FragColor = texture2D(u_texture, v_texCoord) * calcDirectionalLight(u_directionalLight, normal);
}
