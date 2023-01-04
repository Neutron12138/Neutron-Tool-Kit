#version 330 core

in vec2 v_texCoord;

out vec4 o_color;

uniform sampler2D u_texture;

void main()
{
    o_color = vec4(texture(u_texture,v_texCoord).rrr,1.0);
}