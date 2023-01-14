#ifndef __NEUTRON_GRAPHICS_RECTANGLESHAPE_CPP__
#define __NEUTRON_GRAPHICS_RECTANGLESHAPE_CPP__

#include "RectangleShape.hpp"
#include "../../Vertex/VertexArrayObject.hpp"
#include "../../Vertex/VertexAttributeEnum.hpp"

namespace ntk
{
    namespace Graphics
    {
        RectangleShape::RectangleShape() : PolygonShape() {}
        RectangleShape::RectangleShape(const glm::vec2 &position, const glm::vec2 &size) : PolygonShape(), m_rect_position(position), m_rect_size(size) {}
        RectangleShape::RectangleShape(const RectangleShape &from) { *this = from; }
        RectangleShape::~RectangleShape() {}

        RectangleShape &RectangleShape::operator=(const RectangleShape &from)
        {
            PolygonShape::operator=(from);
            m_rect_position = from.m_rect_position;
            m_rect_size = from.m_rect_size;
            return *this;
        }

        const glm::vec2 &RectangleShape::get_rect_position() const
        {
            return m_rect_position;
        }

        void RectangleShape::set_rect_position(const glm::vec2 &position)
        {
            m_rect_position = position;
        }

        const glm::vec2 &RectangleShape::get_rect_size() const
        {
            return m_rect_size;
        }

        void RectangleShape::set_rect_size(const glm::vec2 &size)
        {
            m_rect_size = size;
        }

        void RectangleShape::generate_shape()
        {
            float posx = m_shape_position.x;
            float posy = m_shape_position.y;
            float ow = m_outline_width;
            float x = m_rect_position.x + posx;
            float y = m_rect_position.y + posy;
            float w = m_rect_size.x;
            float h = m_rect_size.y;

            glm::vec3 v0(x - ow, y + ow, 0.0f);
            glm::vec3 v1(x, y, 0.0f);
            glm::vec3 v2(x - ow, y - h - ow, 0.0f);
            glm::vec3 v3(x, y - h, 0.0f);
            glm::vec3 v4(x + w + ow, y - h - ow, 0.0f);
            glm::vec3 v5(x + w, y - h, 0.0f);
            glm::vec3 v6(x + w + ow, y + ow, 0.0f);
            glm::vec3 v7(x + w, y, 0.0f);

            glm::vec2 t0(0.0f, 0.0f);
            glm::vec2 t1(0.0f, 1.0f);
            glm::vec2 t2(1.0f, 1.0f);
            glm::vec2 t3(1.0f, 0.0f);

            std::vector<glm::vec3> vertices = {v1, v3, v5, v7};
            std::vector<glm::vec2> texCoords = {t0, t1, t2, t3};

            m_vertices.vertex_array.generate();
            m_vertices.vertex_array.bind();
            m_vertices.vertex_buffer = VertexBufferObject::createVBO_single(vertices, VertexAttributeEnum::VertexAttributeLocation::Position);
            m_vertices.texCoord_buffer = VertexBufferObject::createVBO_single(texCoords, VertexAttributeEnum::VertexAttributeLocation::TexCoord);
            m_vertices.vertex_array.unbind();
            glBindBuffer(GL_ARRAY_BUFFER, 0);

            vertices = {v0, v1, v2, v3, v4, v5, v6, v7, v0, v1};
            texCoords = {t0, t0, t0, t0, t0, t0, t0, t0, t0, t0};

            m_outline.vertex_array.generate();
            m_outline.vertex_array.bind();
            m_outline.vertex_buffer = VertexBufferObject::createVBO_single(vertices, VertexAttributeEnum::VertexAttributeLocation::Position);
            m_outline.texCoord_buffer = VertexBufferObject::createVBO_single(texCoords, VertexAttributeEnum::VertexAttributeLocation::TexCoord);
            m_outline.vertex_array.unbind();
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        void RectangleShape::update_VAO()
        {
            float posx = m_shape_position.x;
            float posy = m_shape_position.y;
            float ow = m_outline_width;
            float x = m_rect_position.x + posx;
            float y = m_rect_position.y + posy;
            float w = m_rect_size.x;
            float h = m_rect_size.y;

            glm::vec3 v0(x - ow, y + ow, 0.0f);
            glm::vec3 v1(x, y, 0.0f);
            glm::vec3 v2(x - ow, y - h - ow, 0.0f);
            glm::vec3 v3(x, y - h, 0.0f);
            glm::vec3 v4(x + w + ow, y - h - ow, 0.0f);
            glm::vec3 v5(x + w, y - h, 0.0f);
            glm::vec3 v6(x + w + ow, y + ow, 0.0f);
            glm::vec3 v7(x + w, y, 0.0f);

            std::vector<glm::vec3> vertices = {v1, v3, v5, v7};

            m_vertices.vertex_array.bind();
            m_vertices.vertex_buffer.sub_data(vertices);
            m_vertices.vertex_array.unbind();
            glBindBuffer(GL_ARRAY_BUFFER, 0);

            vertices = {v0, v1, v2, v3, v4, v5, v6, v7, v0, v1};

            m_outline.vertex_array.bind();
            m_outline.vertex_buffer.sub_data(vertices);
            m_outline.vertex_array.unbind();
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        void RectangleShape::render()
        {
            m_vertices.vertex_array.bind();
            glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
            m_vertices.vertex_array.unbind();
        }

        void RectangleShape::render(UniformBinder &binder, const UniformDescriber &describer)
        {
            render_polygon(binder, describer);
            render_outline(binder, describer);
        }

        void RectangleShape::render_polygon(UniformBinder &binder, const UniformDescriber &describer)
        {
            binder.set_uniform(describer.get_name(UniformNameEnum::UniformName::Color), m_vertices.color);
            m_vertices.vertex_array.bind();
            glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
            m_vertices.vertex_array.unbind();
        }

        void RectangleShape::render_outline(UniformBinder &binder, const UniformDescriber &describer)
        {
            binder.set_uniform(describer.get_name(UniformNameEnum::UniformName::Color), m_outline.color);
            m_outline.vertex_array.bind();
            glDrawArrays(GL_TRIANGLE_STRIP, 0, 10);
            m_outline.vertex_array.unbind();
        }
    } // namespace Graphics

} // namespace ntk

#endif