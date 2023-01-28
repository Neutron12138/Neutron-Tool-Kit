#version 330 core

in vec3 v_position;
in vec3 v_normal;
in vec2 v_texCoord;

out vec4 o_color;

uniform sampler2D u_sampler0;
uniform vec3 u_view_position;

void main()
{
    vec3 light_position = u_view_position;
    vec3 light_direction = v_position - light_position;

    vec3 texture_color = vec3(texture(u_sampler0,v_texCoord));

    float ambient = 0.1f;
    float diffuse = max(dot(v_normal,-light_direction),0.0);

    vec3 final_color = (ambient + diffuse) *  texture_color;
    o_color = vec4(final_color,1.0);
}