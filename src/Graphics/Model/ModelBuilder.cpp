#ifndef __NEUTRON_GRAPHICS_MODELBUILDER_CPP__
#define __NEUTRON_GRAPHICS_MODELBUILDER_CPP__

#include "ModelBuilder.hpp"

namespace ntk
{
    namespace Graphics
    {
        ModelBuilder::ModelBuilder() {}
        ModelBuilder::ModelBuilder(const ModelBuilder &from) {}
        ModelBuilder::~ModelBuilder() {}
        ModelBuilder &ModelBuilder::operator=(const ModelBuilder &from) { return *this; }

        Model<> ModelBuilder::create_quad_triangulated(const glm::vec2 &size)
        {
            glm::vec2 half = size / 2.0f;

            std::vector<glm::vec3> vertices =
                {
                    glm::vec3(-half.x, half.y, 0.0f),
                    glm::vec3(-half.x, -half.y, 0.0f),
                    glm::vec3(half.x, -half.y, 0.0f),

                    glm::vec3(-half.x, half.y, 0.0f),
                    glm::vec3(half.x, -half.y, 0.0f),
                    glm::vec3(half.x, half.y, 0.0f),
                };

            std::vector<glm::vec3> normals =
                {
                    glm::vec3(0.0f, 0.0f, 1.0f),
                    glm::vec3(0.0f, 0.0f, 1.0f),
                    glm::vec3(0.0f, 0.0f, 1.0f),

                    glm::vec3(0.0f, 0.0f, 1.0f),
                    glm::vec3(0.0f, 0.0f, 1.0f),
                    glm::vec3(0.0f, 0.0f, 1.0f),
                };

            std::vector<glm::vec2> texCoords =
                {
                    glm::vec2(0.0f, 0.0f),
                    glm::vec2(0.0f, 1.0f),
                    glm::vec2(1.0f, 1.0f),

                    glm::vec2(0.0f, 0.0f),
                    glm::vec2(1.0f, 1.0f),
                    glm::vec2(1.0f, 0.0f),
                };

            return Model<>(vertices, normals, texCoords);
        }

        Model<> ModelBuilder::create_axis(const glm::vec3 &size)
        {
            glm::vec3 half = size / 2.0f;

            std::vector<glm::vec3> vertices;

            if (size.x != 0.0f)
            {
                vertices.push_back(glm::vec3(-half.x, 0.0f, 0.0f));
                vertices.push_back(glm::vec3(half.x, 0.0f, 0.0f));
            }

            if (size.y != 0.0f)
            {
                vertices.push_back(glm::vec3(0.0f, -half.y, 0.0f));
                vertices.push_back(glm::vec3(0.0f, half.y, 0.0f));
            }

            if (size.z != 0.0f)
            {
                vertices.push_back(glm::vec3(0.0f, 0.0f, -half.z));
                vertices.push_back(glm::vec3(0.0f, 0.0f, half.z));
            }

            return Model<>(vertices, std::vector<glm::vec3>(), std::vector<glm::vec2>());
        }

        Model<> ModelBuilder::create_gridxy_wireframe(const glm::vec2 &size, const glm::uvec2 &pieces)
        {
            glm::vec2 half = size / 2.0f;
            glm::vec2 span = glm::vec2(
                size.x / static_cast<float>(pieces.x),
                size.y / static_cast<float>(pieces.y));

            std::vector<glm::vec3> vertices;

            for (float x = -half.x; x <= half.x; x += span.x)
            {
                vertices.push_back(glm::vec3(x, -half.y, 0.0f));
                vertices.push_back(glm::vec3(x, half.y, 0.0f));
            }

            for (float y = -half.y; y <= half.y; y += span.y)
            {
                vertices.push_back(glm::vec3(-half.x, y, 0.0f));
                vertices.push_back(glm::vec3(half.x, y, 0.0f));
            }

            return Model<>(vertices, std::vector<glm::vec3>(), std::vector<glm::vec2>());
        }
    } // namespace Graphics

} // namespace ntk

#endif