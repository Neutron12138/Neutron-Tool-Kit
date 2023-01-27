#version 330 core

layout (points) in;
layout (triangle_strip, max_vertices = 74) out;

const float PI = 3.1415;
const float PI2 = 2.0 * PI;
const float radius = 0.1f;
const float width = 0.1f;

void main()
{
    for(float i = 0.0;i <= PI2;i += PI2 / 36.0f)
    {
        float x0 = cos(i) * radius;
        float y0 = sin(i) * radius;
        float x1 = cos(i) * (radius + width);
        float y1 = sin(i) * (radius + width);

        gl_Position = gl_in[0].gl_Position + vec4(x0, y0, 0.0, 0.0); 
        EmitVertex();
        gl_Position = gl_in[0].gl_Position + vec4(x1, y1, 0.0, 0.0); 
        EmitVertex();
    }

    EndPrimitive();
}