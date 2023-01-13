#ifndef __NEUTRON_GRAPHICS_POINTSHAPE_CPP__
#define __NEUTRON_GRAPHICS_POINTSHAPE_CPP__

#include "PointShape.hpp"

namespace ntk
{
    namespace Graphics
    {
        PointShape::PointShape() : BaseShape() {}
        PointShape::PointShape(const glm::vec2 &position) : BaseShape(position) {}
        PointShape::PointShape(const PointShape &from) { *this = from; }
        PointShape::~PointShape() {}

        PointShape &PointShape::operator=(const PointShape &from)
        {
            BaseShape::operator=(from);
            return *this;
        }

        void PointShape::generate_shape()
        {
            std::vector<glm::vec3> vertices =
                {
                    glm::vec3(m_shape_position.x, m_shape_position.y, 0.0f),
                };
            std::vector<glm::vec2> texCoords =
                {
                    glm::vec2(0.0f, 0.0f),
                };

            m_vertices.vertex_array.generate();
            m_vertices.vertex_array.bind();
            m_vertices.vertex_buffer = VertexBufferObject::createVBO_single(vertices, VertexAttributeEnum::VertexAttributeLocation::Position); // VertexBufferObject::createVBO_single(1 * sizeof(glm::vec3), nullptr, GL_STATIC_DRAW, VertexAttributeEnum::VertexAttributeLocation::Position, 3, GL_FLOAT, 1 * sizeof(glm::vec3));
            m_vertices.texCoord_buffer = VertexBufferObject::createVBO_single(texCoords, VertexAttributeEnum::VertexAttributeLocation::TexCoord);
            m_vertices.vertex_array.unbind();
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        void PointShape::update_VAO()
        {
            std::vector<glm::vec3> vertices =
                {
                    glm::vec3(m_shape_position.x, m_shape_position.y, 0.0f),
                };

            m_vertices.vertex_array.bind();
            m_vertices.vertex_buffer.sub_data(vertices);
            m_vertices.vertex_array.unbind();
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        void PointShape::render()
        {
            m_vertices.vertex_array.bind();
            glDrawArrays(GL_POINTS, 0, 1);
            m_vertices.vertex_array.unbind();
        }

        void PointShape::render(UniformBinder &binder, const UniformDescriber &describer)
        {
            binder.set_uniform(describer.get_name(UniformNameEnum::UniformName::Color), m_vertices.color);
            render();
        }
    } // namespace Graphics

} // namespace ntk

#endif