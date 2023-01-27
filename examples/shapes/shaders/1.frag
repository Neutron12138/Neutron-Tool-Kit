#version 330 core

in vec2 v_texCoord;
out vec4 o_color;

uniform sampler2D u_sampler0;

void main()
{
    o_color = texture(u_sampler0,v_texCoord);
}