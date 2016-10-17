#version 150

uniform mat4 m4_MVP;

in vec3 v3_Position;

void main()
{
	gl_Position = m4_MVP * vec4(v3_Position, 1.0);
}