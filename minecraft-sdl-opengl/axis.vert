#version 330 core

out vec3 vs_out_col;

vec3 pos[4] = vec3[4](
  vec3(0,0,0),
  vec3(3,0,0),
  vec3(0,2,0),
  vec3(0,0,1)
);

vec3 col[3] = vec3[3] (
  vec3(1,0,0),
  vec3(0,1,0),
  vec3(0,0,1)
);

uniform mat4 MVP;

void main()
{
  //int vertInd = (gl_VertexID % 2 == 0) ? 0 : gl_VertexID;
  //gl_Position = MVP *  vec4( pos[vertInd], 1 );
  gl_Position = MVP *  vec4( pos[gl_VertexID%2 * (gl_VertexID/2+1)], 1 );
  vs_out_col = col[ gl_VertexID/2 ]; //egész osztás
}