#ifndef __NEUTRON_GRAPHICS_BASESHAPE_CPP__
#define __NEUTRON_GRAPHICS_BASESHAPE_CPP__

#include "BaseShape.hpp"

namespace ntk
{
    namespace Graphics
    {
        BaseShape::VertexData::VertexData() {}
        BaseShape::VertexData::VertexData(const BaseShape::VertexData &from) { *this = from; }
        BaseShape::VertexData::~VertexData() {}

        BaseShape::VertexData &BaseShape::VertexData::operator=(const BaseShape::VertexData &from)
        {
            vertex_array = from.vertex_array;
            vertex_buffer = from.vertex_buffer;
            texCoord_buffer = from.texCoord_buffer;
            color = from.color;
            return *this;
        }

        void BaseShape::VertexData::release()
        {
            vertex_array.delete_object();
            vertex_buffer.delete_object();
            texCoord_buffer.delete_object();
        }

        BaseShape::BaseShape() : Sprite2D() {}
        BaseShape::BaseShape(const glm::vec2 &position) : m_shape_position(position) {}
        BaseShape::BaseShape(const BaseShape &from) { *this = from; }
        BaseShape::~BaseShape() {}

        BaseShape &BaseShape::operator=(const BaseShape &from)
        {
            Sprite2D::operator=(from);
            m_shape_position = from.m_shape_position;
            // m_texture = from.m_texture;
            m_vertices = from.m_vertices;
            return *this;
        }

        const glm::vec2 &BaseShape::get_shape_position() const
        {
            return m_shape_position;
        }

        void BaseShape::set_shape_position(const glm::vec2 &position)
        {
            m_shape_position = position;
        }

        /*
                const Texture2D &BaseShape::get_texture() const
                {
                    return m_texture;
                }

                void BaseShape::set_texture(const Texture2D &texture)
                {
                    m_texture = texture;
                }
        */

        const glm::vec4 &BaseShape::get_fill_color() const
        {
            return m_vertices.color;
        }

        void BaseShape::set_fill_color(const glm::vec4 &fill_color)
        {
            m_vertices.color = fill_color;
        }

        Sprite2D::PositionType BaseShape::get_position()
        {
            return m_translation + m_shape_position;
        }

        void BaseShape::release()
        {
            m_vertices.release();
        }
    } // namespace Graphics

} // namespace ntk

#endif