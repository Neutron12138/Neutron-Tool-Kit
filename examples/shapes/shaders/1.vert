#version 330 core

layout(location=0)in vec3 a_position;
layout(location=1)in vec3 a_normal;
layout(location=2)in vec2 a_texCoord;

out vec3 v_position;
out vec3 v_normal;
out vec2 v_texCoord;

uniform mat4 u_projection;
uniform mat4 u_view;
uniform mat4 u_model;

void main()
{
    gl_Position = u_projection * u_view * u_model * vec4(a_position,1.0);
    v_position = vec3(u_model * vec4(a_position,1.0));
    v_normal = normalize(vec3(u_model * vec4(a_normal,1.0)));
    v_texCoord = a_texCoord;
}