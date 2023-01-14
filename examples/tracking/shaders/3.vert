#version 330 core

layout(location=0)in vec3 a_position;

out vec3 v_position;

// 模型矩阵
uniform mat4 u_model;
// 视图矩阵
uniform mat4 u_view;
// 投影矩阵
uniform mat4 u_projection;

void main()
{
    // 计算顶点最终位置
    gl_Position = u_projection * u_view * u_model * vec4(a_position,1.0);
    v_position = vec3(u_model * vec4(a_position,1.0));
}