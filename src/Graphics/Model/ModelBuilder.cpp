#ifndef __NEUTRON_GRAPHICS_MODELBUILDER_CPP__
#define __NEUTRON_GRAPHICS_MODELBUILDER_CPP__

#include "ModelBuilder.hpp"

namespace ntk
{
    namespace Graphics
    {
        ModelObject ModelBuilder::create_quad_triangulated(const glm::vec2 &size)
        {
            const glm::vec2 half = size / 2.0f;

            const glm::vec3 p0 = glm::vec3(-half.x, half.y, 0.0f);
            const glm::vec3 p1 = glm::vec3(-half.x, -half.y, 0.0f);
            const glm::vec3 p2 = glm::vec3(half.x, -half.y, 0.0f);
            const glm::vec3 p3 = glm::vec3(half.x, half.y, 0.0f);

            const glm::vec3 n = glm::vec3(0.0f, 0.0f, 1.0f);

            const glm::vec2 t0 = glm::vec2(0.0f, 0.0f);
            const glm::vec2 t1 = glm::vec2(0.0f, 1.0f);
            const glm::vec2 t2 = glm::vec2(1.0f, 1.0f);
            const glm::vec2 t3 = glm::vec2(1.0f, 0.0f);

            // 左上角
            const Vertex v0 = Vertex(p0, n, t0);
            // 左下角
            const Vertex v1 = Vertex(p1, n, t1);
            // 右下角
            const Vertex v2 = Vertex(p2, n, t2);
            // 右上角
            const Vertex v3 = Vertex(p3, n, t3);

            std::vector<Vertex> vertices =
                {
                    v0,
                    v1,
                    v2,

                    v0,
                    v2,
                    v3,
                };

            return ModelObject(vertices, DrawInfo(PrimitiveType::PrimitiveType::Triangles, 0, vertices.size()));
        }

        ModelObject ModelBuilder::create_axis(const glm::vec3 &size)
        {
            glm::vec3 half = size / 2.0f;

            std::vector<Vertex> vertices;

            if (half.x != 0.0f)
            {
                vertices.push_back(Vertex(glm::vec3(half.x, 0.0f, 0.0f), glm::vec3(), glm::vec2()));
                vertices.push_back(Vertex(glm::vec3(-half.x, 0.0f, 0.0f), glm::vec3(), glm::vec2()));
            }

            if (half.y != 0.0f)
            {
                vertices.push_back(Vertex(glm::vec3(0.0f, half.y, 0.0f), glm::vec3(), glm::vec2()));
                vertices.push_back(Vertex(glm::vec3(0.0f, -half.y, 0.0f), glm::vec3(), glm::vec2()));
            }

            if (half.z != 0.0f)
            {
                vertices.push_back(Vertex(glm::vec3(0.0f, 0.0f, half.z), glm::vec3(), glm::vec2()));
                vertices.push_back(Vertex(glm::vec3(0.0f, 0.0f, -half.z), glm::vec3(), glm::vec2()));
            }

            return ModelObject(vertices, DrawInfo(PrimitiveType::PrimitiveType::Lines, 0, vertices.size()));
        }

        ModelObject ModelBuilder::create_gridxy_wireframe(const glm::vec2 &size, const glm::uvec2 &pieces)
        {
            const glm::vec2 half = glm::abs(size / 2.0f);
            const glm::vec2 span = glm::abs(glm::vec2(
                size.x / (2.0f + static_cast<float>(pieces.x)),
                size.y / (2.0f + static_cast<float>(pieces.y))));

            std::vector<Vertex> vertices;

            for (float x = -half.x; x <= half.x; x += span.x)
            {
                vertices.push_back(Vertex(glm::vec3(x, half.y, 0.0f), glm::vec3(), glm::vec2()));
                vertices.push_back(Vertex(glm::vec3(x, -half.y, 0.0f), glm::vec3(), glm::vec2()));
            }

            for (float y = -half.y; y <= half.y; y += span.y)
            {
                vertices.push_back(Vertex(glm::vec3(half.x, y, 0.0f), glm::vec3(), glm::vec2()));
                vertices.push_back(Vertex(glm::vec3(-half.x, y, 0.0f), glm::vec3(), glm::vec2()));
            }

            return ModelObject(vertices, DrawInfo(PrimitiveType::PrimitiveType::Lines, 0, vertices.size()));
        }

        ModelObject ModelBuilder::create_regular_polygon_triangulated(float radius, std::uint32_t sides)
        {
            const float PI = 3.1415926f;
            const float span = 2 * PI / static_cast<float>(sides);

            std::vector<Vertex> vertices;

            const glm::vec3 n = glm::vec3(0.0f, 0.0f, 1.0f);
            const Vertex center = Vertex(glm::vec3(0.0f, 0.0f, 0.0f), n, glm::vec2(0.5f, 0.5f));
            for (float angle = 0.0f; angle <= 2 * PI; angle += span)
            {
                const float next_angle = angle + span;

                const glm::vec3 v1 = glm::vec3(glm::cos(angle), glm::sin(angle), 0.0f) * radius;
                const glm::vec3 v2 = glm::vec3(glm::cos(next_angle), glm::sin(next_angle), 0.0f) * radius;

                const glm::vec2 t1 = glm::vec2(v1.x, -v1.y) / radius / 2.0f + 0.5f;
                const glm::vec2 t2 = glm::vec2(v2.x, -v2.y) / radius / 2.0f + 0.5f;

                vertices.push_back(center);
                vertices.push_back(Vertex(v1, n, t1));
                vertices.push_back(Vertex(v2, n, t2));
            }

            return ModelObject(vertices, DrawInfo(PrimitiveType::PrimitiveType::Triangles, 0, vertices.size()));
        }

        ModelObject ModelBuilder::create_points(const std::vector<glm::vec3> &points)
        {
            std::vector<Vertex> vertices;
            for (std::size_t i = 0; i < points.size(); i++)
            {
                vertices.push_back(Vertex(points.at(i), glm::vec3(), glm::vec2()));
            }
            return ModelObject(vertices, DrawInfo(PrimitiveType::PrimitiveType::Points, 0, vertices.size()));
        }

        ModelObject ModelBuilder::create_lines(const std::vector<glm::vec3> &lines)
        {
            const std::size_t size = lines.size() % 2 == 0 ? lines.size() : lines.size() - 1;

            std::vector<Vertex> vertices;
            for (std::size_t i = 0; i < size; i++)
            {
                vertices.push_back(Vertex(lines.at(i), glm::vec3(), glm::vec2()));
            }
            return ModelObject(vertices, DrawInfo(PrimitiveType::PrimitiveType::Lines, 0, vertices.size()));
        }

        ModelObject ModelBuilder::create_cuboid_triangulated(const glm::vec3 &size)
        {
            const glm::vec3 half = size / 2.0f;

            // 正Z半轴的4个顶点
            glm::vec3 const v0 = glm::vec3(-half.x, half.y, half.z);
            glm::vec3 const v1 = glm::vec3(-half.x, -half.y, half.z);
            glm::vec3 const v2 = glm::vec3(half.x, -half.y, half.z);
            glm::vec3 const v3 = glm::vec3(half.x, half.y, half.z);

            // 负Z半轴的4个顶点
            glm::vec3 const v4 = glm::vec3(-half.x, half.y, -half.z);
            glm::vec3 const v5 = glm::vec3(-half.x, -half.y, -half.z);
            glm::vec3 const v6 = glm::vec3(half.x, -half.y, -half.z);
            glm::vec3 const v7 = glm::vec3(half.x, half.y, -half.z);

            // 法线
            glm::vec3 const nx = glm::vec3(1.0f, 0.0f, 0.0f);
            glm::vec3 const ny = glm::vec3(0.0f, 1.0f, 0.0f);
            glm::vec3 const nz = glm::vec3(0.0f, 0.0f, 1.0f);

            // 纹理坐标
            glm::vec2 const t0 = glm::vec2(0.0f, 0.0f);
            glm::vec2 const t1 = glm::vec2(0.0f, 1.0f);
            glm::vec2 const t2 = glm::vec2(1.0f, 1.0f);
            glm::vec2 const t3 = glm::vec2(1.0f, 0.0f);

            std::vector<Vertex> vertices =
                {
                    // 正Z轴
                    Vertex(v0, nz, t0),
                    Vertex(v1, nz, t1),
                    Vertex(v2, nz, t2),
                    Vertex(v0, nz, t0),
                    Vertex(v2, nz, t2),
                    Vertex(v3, nz, t3),

                    // 负Z轴
                    Vertex(v7, -nz, t0),
                    Vertex(v6, -nz, t1),
                    Vertex(v5, -nz, t2),
                    Vertex(v7, -nz, t0),
                    Vertex(v5, -nz, t2),
                    Vertex(v4, -nz, t3),

                    // 正X轴
                    Vertex(v3, nx, t0),
                    Vertex(v2, nx, t1),
                    Vertex(v6, nx, t2),
                    Vertex(v3, nx, t0),
                    Vertex(v6, nx, t2),
                    Vertex(v7, nx, t3),

                    // 负X轴
                    Vertex(v4, -nx, t0),
                    Vertex(v5, -nx, t1),
                    Vertex(v1, -nx, t2),
                    Vertex(v4, -nx, t0),
                    Vertex(v1, -nx, t2),
                    Vertex(v0, -nx, t3),
                    
                    // 正Y轴
                    Vertex(v4, ny, t0),
                    Vertex(v0, ny, t1),
                    Vertex(v3, ny, t2),
                    Vertex(v4, ny, t0),
                    Vertex(v3, ny, t2),
                    Vertex(v7, ny, t3),

                    // 负Y轴
                    Vertex(v6, -ny, t0),
                    Vertex(v2, -ny, t1),
                    Vertex(v1, -ny, t2),
                    Vertex(v6, -ny, t0),
                    Vertex(v1, -ny, t2),
                    Vertex(v5, -ny, t3),
                };
            return ModelObject(vertices, DrawInfo(PrimitiveType::PrimitiveType::Triangles, 0, vertices.size()));
        }

        ModelObject ModelBuilder::create_cube_triangulated(float size)
        {
            return create_cuboid_triangulated(glm::vec3(size, size, size));
        }
    } // namespace Graphics

} // namespace ntk

#endif