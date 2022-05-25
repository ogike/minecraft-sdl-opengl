#version 330 core

// pipeline-ból bejövő per-fragment attribútumok
in vec3 vs_out_pos;
in vec3 vs_out_norm;
in vec2 vs_out_tex;

out vec4 fs_out_col;

// irány fényforrás: fény iránya
uniform vec3 light_dir = vec3(-1,-1,-1);

//point light_dir
uniform vec3 light_pos = vec3(3,0,0);

uniform vec3 eye; //eye pos

// fénytulajdonságok: ambiens, diffúz, spekuláris
uniform vec3 La = vec3(0.4, 0.4, 0.4);
uniform vec3 Ld = vec3(0.6, 0.6, 0.6);
uniform vec3 Ls = vec3(0.9, 0.9, 0.9);

uniform sampler2D texImage;

void main()
{

	vec3 ambient = La;

	vec3 normal = normalize(vs_out_norm);
	vec3 toLight_dir = normalize(-light_dir);
	vec3 toLight_point = normalize(light_pos - vs_out_pos);
	
	//diffuse
	float di_dir = clamp( dot(normal, toLight_dir), 0, 1 );
	float di_point = clamp( dot(normal, toLight_point), 0, 1 );
	vec3 diffuse = (di_dir + di_point) * Ld;

	//reflection
	vec3 ref_dir = reflect( normalize(light_dir), normal );
	vec3 ref_point = reflect( -toLight_point, normal );

	vec3 toEye = normalize(eye - vs_out_pos);

	float si_dir = pow( clamp( dot(toEye, ref_dir), 0, 1), 256);
	float si_point = pow( clamp( dot(toEye, ref_point), 0, 1), 256);
	vec3 specular = (si_dir + si_point) * Ls;
	
	fs_out_col = vec4(ambient + diffuse + specular, 1) * texture(texImage, vs_out_tex);
}