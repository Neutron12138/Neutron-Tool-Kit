#ifndef __NEUTRON_GRAPHICS_POLYGONSHAPE_CPP__
#define __NEUTRON_GRAPHICS_POLYGONSHAPE_CPP__

#include "PolygonShape.hpp"

namespace ntk
{
    namespace Graphics
    {
        PolygonShape::PolygonShape() : BaseShape() {}
        PolygonShape::PolygonShape(const glm::vec2 &position) : BaseShape(position) {}
        PolygonShape::PolygonShape(const PolygonShape &from) { *this = from; }
        PolygonShape::~PolygonShape() {}

        PolygonShape &PolygonShape::operator=(const PolygonShape &from)
        {
            BaseShape::operator=(from);
            m_outline = from.m_outline;
            m_outline_width = from.m_outline_width;
            return *this;
        }

        const glm::vec4 &PolygonShape::get_outline_color() const
        {
            return m_outline.color;
        }

        void PolygonShape::set_outline_color(const glm::vec4 &outline_color)
        {
            m_outline.color = outline_color;
        }

        float PolygonShape::get_outline_width() const
        {
            return m_outline_width;
        }

        void PolygonShape::set_outline_width(float outline_width)
        {
            m_outline_width = outline_width;
        }

        void PolygonShape::release()
        {
            BaseShape::release();
            m_outline.release();
        }
    } // namespace Graphics

} // namespace ntk

#endif