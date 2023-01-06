#version 330 core

in vec3 v_position;
in vec3 v_normal;
out vec4 o_color;

// 颜色
uniform vec3 u_color;
// 视线位置
uniform vec3 u_view_position;

void main()
{
    vec3 view_to_object = normalize(u_view_position - v_position);
    vec3 reflect_vec = normalize(reflect(view_to_object,v_normal));

    // 环境光
    float ambient = 0.1;
    // 漫射光
    float diffuse = max(dot(v_normal,view_to_object),0.0);
    // 镜面光
    float specular = pow(max(dot(reflect_vec,view_to_object),0.0),32.0);

    // 最终颜色
    o_color = (ambient + diffuse + specular) * vec4(u_color,1.0);
}