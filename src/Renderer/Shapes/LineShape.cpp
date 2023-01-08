#ifndef __NEUTRON_GRAPHICS_LINESHAPE_CPP__
#define __NEUTRON_GRAPHICS_LINESHAPE_CPP__

#include "LineShape.hpp"

namespace ntk
{
    namespace Graphics
    {
        LineShape::LineShape() : BaseShape() {}
        LineShape::LineShape(const glm::vec2 &vertex1, const glm::vec2 &vertex2) : BaseShape(), m_vertex1(vertex1), m_vertex2(vertex2) {}
        LineShape::LineShape(const LineShape &from) { *this = from; }
        LineShape::~LineShape() {}

        LineShape &LineShape::operator=(const LineShape &from)
        {
            BaseShape::operator=(from);
            m_vertex1 = from.m_vertex1;
            m_vertex2 = from.m_vertex2;
            return *this;
        }

        const glm::vec2 &LineShape::get_vertex1() const
        {
            return m_vertex1;
        }

        const glm::vec2 &LineShape::get_vertex2() const
        {
            return m_vertex2;
        }

        void LineShape::set_vertex1(const glm::vec2 &vertex)
        {
            m_vertex1 = vertex;
        }

        void LineShape::set_vertex2(const glm::vec2 &vertex)
        {
            m_vertex2 = vertex;
        }

        void LineShape::generate_shape()
        {
            std::vector<glm::vec3> vertices =
                {
                    glm::vec3(m_shape_position.x + m_vertex1.x, m_shape_position.y + m_vertex1.y, 0.0f),
                    glm::vec3(m_shape_position.x + m_vertex2.x, m_shape_position.y + m_vertex2.y, 0.0f),
                };
            std::vector<glm::vec2> texCoords =
                {
                    glm::vec2(0.0f, 0.0f),
                    glm::vec2(0.0f, 0.0f),
                };

            m_vertices.vertex_array.generate();
            m_vertices.vertex_array.bind();
            m_vertices.vertex_buffer = VertexBufferObject::createVBO_single(vertices, VertexAttributeEnum::VertexAttributeLocation::Position);
            m_vertices.texCoord_buffer = VertexBufferObject::createVBO_single(texCoords, VertexAttributeEnum::VertexAttributeLocation::TexCoord);
            m_vertices.vertex_array.unbind();
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        void LineShape::update_VAO()
        {
            std::vector<glm::vec3> vertices =
                {
                    glm::vec3(m_shape_position.x + m_vertex1.x, m_shape_position.y + m_vertex1.y, 0.0f),
                    glm::vec3(m_shape_position.x + m_vertex2.x, m_shape_position.y + m_vertex2.y, 0.0f),
                };

            m_vertices.vertex_array.bind();
            m_vertices.vertex_buffer.sub_data(vertices);
            m_vertices.vertex_array.unbind();
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        void LineShape::render()
        {
            m_vertices.vertex_array.bind();
            glDrawArrays(GL_LINES, 0, 2);
            m_vertices.vertex_array.unbind();
        }

        void LineShape::render(UniformBinder &binder, const UniformDescriber &describer)
        {
            binder.set_uniform(describer.get_name(UniformNameEnum::UniformName::Color), m_vertices.color);
            render();
        }
    } // namespace Graphics

} // namespace ntk

#endif