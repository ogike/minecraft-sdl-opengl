#version 130

//the lines for the cross hair
vec4 positions[4] = vec4[4](
	vec4(-0.02, 0, 0, 1),
	vec4(+0.02, 0, 0, 1),

	vec4( 0, +0.02, 0, 1),
	vec4( 0, -0.02, 0, 1)
);

out vec4 vs_out_col;
out vec4 vs_out_pos;

uniform float window_ratio;

void main()
{
	vec4 orig_position = positions[gl_VertexID];
	gl_Position = vec4(orig_position.x / window_ratio, orig_position.yzw);
	vs_out_col	= vec4(1, 1, 1, 1);
	vs_out_pos = gl_Position;
}