#version 330 core

in vec3 v_position;
out vec4 o_color;

// 颜色
uniform vec3 u_color;

void main()
{
    o_color = vec4(u_color,1.0);
}