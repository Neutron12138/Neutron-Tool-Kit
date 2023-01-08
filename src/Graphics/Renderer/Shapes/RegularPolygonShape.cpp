#ifndef __NEUTRON_GRAPHICS_REGULARPOLYGONSHAPE_CPP__
#define __NEUTRON_GRAPHICS_REGULARPOLYGONSHAPE_CPP__

#include "RegularPolygonShape.hpp"

namespace ntk
{
    namespace Graphics
    {
        RegularPolygonShape::RegularPolygonShape() : PolygonShape() {}
        RegularPolygonShape::RegularPolygonShape(std::uint32_t sides, float radius) : PolygonShape(), m_regpol_sides(sides), m_regpol_radius(radius) {}
        RegularPolygonShape::RegularPolygonShape(const RegularPolygonShape &from) { *this = from; }
        RegularPolygonShape::~RegularPolygonShape() {}

        RegularPolygonShape &RegularPolygonShape::operator=(const RegularPolygonShape &from)
        {
            PolygonShape::operator=(from);
            m_regpol_sides = from.m_regpol_sides;
            m_regpol_radius = from.m_regpol_radius;
            return *this;
        }

        std::uint32_t RegularPolygonShape::get_regpol_sides() const
        {
            return m_regpol_sides;
        }

        void RegularPolygonShape::set_regpol_sides(std::uint32_t sides)
        {
            m_regpol_sides = sides;
        }

        float RegularPolygonShape::get_regpol_radius() const
        {
            return m_regpol_radius;
        }

        void RegularPolygonShape::set_regpol_radius(float radius)
        {
            m_regpol_radius = radius;
        }

        void RegularPolygonShape::generate_shape()
        {
            glm::vec3 pos = glm::vec3(m_shape_position.x, m_shape_position.y, 0.0f);
            float ow = m_outline_width;
            float radius = m_regpol_radius;

            std::vector<glm::vec3> vertices;
            std::vector<glm::vec2> texCoords;
            std::vector<glm::vec3> outline_ver;
            std::vector<glm::vec2> outline_tex;

            glm::vec3 v0 = pos + glm::vec3(glm::cos(0.0f) * (radius + ow), glm::sin(0.0f) * (radius + ow), 0.0f);
            glm::vec3 v1 = pos + glm::vec3(glm::cos(0.0f) * radius, glm::sin(0.0f) * radius, 0.0f);
            glm::vec2 t0 = glm::vec2(0.0f, 0.0f);

            float span = glm::radians(360.0f) / static_cast<float>(m_regpol_sides);
            for (float i = 0; i <= glm::radians(360.0f); i += span)
            {
                glm::vec3 v2 = pos + glm::vec3(glm::cos(i) * (radius + ow), glm::sin(i) * (radius + ow), 0.0f);
                glm::vec3 v3 = pos + glm::vec3(glm::cos(i) * radius, glm::sin(i) * radius, 0.0f);

                glm::vec2 t1 = glm::vec2(glm::cos(i) / 2.0f + 0.5f, -glm::sin(i) / 2.0f + 0.5f);

                vertices.push_back(v3);
                texCoords.push_back(t1);

                outline_ver.push_back(v2);
                outline_ver.push_back(v3);
                outline_tex.push_back(t0);
                outline_tex.push_back(t0);
            }

            outline_ver.push_back(v0);
            outline_ver.push_back(v1);
            outline_tex.push_back(t0);
            outline_tex.push_back(t0);

            m_vertices.vertex_array.generate();
            m_vertices.vertex_array.bind();
            m_vertices.vertex_buffer = VertexBufferObject::createVBO_single(vertices, VertexAttributeEnum::VertexAttributeLocation::Position);
            m_vertices.texCoord_buffer = VertexBufferObject::createVBO_single(texCoords, VertexAttributeEnum::VertexAttributeLocation::TexCoord);
            m_vertices.vertex_array.unbind();
            glBindBuffer(GL_ARRAY_BUFFER, 0);

            m_outline.vertex_array.generate();
            m_outline.vertex_array.bind();
            m_outline.vertex_buffer = VertexBufferObject::createVBO_single(outline_ver, VertexAttributeEnum::VertexAttributeLocation::Position);
            m_outline.texCoord_buffer = VertexBufferObject::createVBO_single(outline_tex, VertexAttributeEnum::VertexAttributeLocation::TexCoord);
            m_outline.vertex_array.unbind();
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        void RegularPolygonShape::update_VAO()
        {
        }

        void RegularPolygonShape::render()
        {
            m_vertices.vertex_array.bind();
            glDrawArrays(GL_TRIANGLE_FAN, 0, m_regpol_sides);
            m_vertices.vertex_array.unbind();
        }

        void RegularPolygonShape::render(UniformBinder &binder, const UniformDescriber &describer)
        {
            render_polygon(binder, describer);
            render_outline(binder, describer);
        }

        void RegularPolygonShape::render_polygon(UniformBinder &binder, const UniformDescriber &describer)
        {
            binder.set_uniform(describer.get_name(UniformNameEnum::UniformName::Color), m_vertices.color);
            m_vertices.vertex_array.bind();
            glDrawArrays(GL_TRIANGLE_FAN, 0, m_regpol_sides);
            m_vertices.vertex_array.unbind();
        }

        void RegularPolygonShape::render_outline(UniformBinder &binder, const UniformDescriber &describer)
        {
            binder.set_uniform(describer.get_name(UniformNameEnum::UniformName::Color), m_outline.color);
            m_outline.vertex_array.bind();
            glDrawArrays(GL_TRIANGLE_STRIP, 0, m_regpol_sides * 2 + 2);
            m_outline.vertex_array.unbind();
        }
    } // namespace Graphics

} // namespace ntk

#endif