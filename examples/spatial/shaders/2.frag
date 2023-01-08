#version 330 core

struct Material
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    vec3 emission;
    float shininess;
};

in vec3 v_position;
in vec3 v_normal;
out vec4 o_color;

uniform vec3 u_light_color;
uniform vec3 u_view_position;
uniform Material u_material;

void main()
{
    vec3 light_direction = normalize(vec3(0.0,0.0,0.0) - u_view_position);
    vec3 view_to_object = normalize(v_position - u_view_position);
    vec3 reflect_vec = normalize(reflect(-light_direction,v_normal));

    vec3 ambient = 0.1 * u_material.ambient;
    vec3 diffuse1 = max(dot(v_normal,-light_direction),0.0) * u_material.diffuse;
    vec3 specular1 = pow(max(dot(reflect_vec,-view_to_object),0.0),u_material.shininess) * u_material.specular;
    vec3 diffuse2 = max(dot(-v_normal,-light_direction),0.0) * u_material.diffuse;
    vec3 specular2 = pow(max(dot(-reflect_vec,-view_to_object),0.0),u_material.shininess) * u_material.specular;

    vec3 final_color = (ambient + diffuse1 + specular1 + diffuse2 + specular2) * u_light_color + u_material.emission;
    o_color = vec4(final_color,1.0);
}