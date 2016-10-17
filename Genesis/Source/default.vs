#version 410

in vec3 v3_Position

void main()
{
	gl_Position = vec4(v3_Position, 1.0);
}