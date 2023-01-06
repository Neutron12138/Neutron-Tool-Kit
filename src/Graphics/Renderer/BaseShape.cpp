#ifndef __NEUTRON_GRAPHICS_BASESHAPE_CPP__
#define __NEUTRON_GRAPHICS_BASESHAPE_CPP__

#include "BaseShape.hpp"

namespace ntk
{
    namespace Graphics
    {
        BaseShape::BaseShape() : PrimitiveSprite2D() {}
        BaseShape::BaseShape(const glm::vec2 &position) : m_shape_position(position) {}
        BaseShape::BaseShape(const BaseShape &from) { *this = from; }
        BaseShape::~BaseShape() {}

        BaseShape &BaseShape::operator=(const BaseShape &from)
        {
            PrimitiveSprite2D::operator=(from);
            m_shape_position = from.m_shape_position;
            m_texture = from.m_texture;
            m_VBOs = from.m_VBOs;
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

        const Texture2D &BaseShape::get_texture() const
        {
            return m_texture;
        }

        void BaseShape::set_texture(const Texture2D &texture)
        {
            m_texture = texture;
        }

        Sprite2D::PositionType BaseShape::get_position()
        {
            return m_translation + m_shape_position;
        }

        void BaseShape::release()
        {
            PrimitiveSprite2D::release();
            for (auto &i : m_VBOs)
            {
                i.delete_object();
            }
        }
    } // namespace Graphics

} // namespace ntk

#endif