#version 130

in vec4 vs_out_col;
in vec4 vs_out_pos;

out vec4 fs_out_col;

void main()
{
	fs_out_col = vs_out_col;
}