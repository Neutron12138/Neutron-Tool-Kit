#ifndef __NEUTRON_GRAPHICS_RECTPROJECTION_CPP__
#define __NEUTRON_GRAPHICS_RECTPROJECTION_CPP__

#include <glm/gtc/matrix_transform.hpp>
#include "RectProjection.hpp"

namespace ntk
{
    namespace Graphics
    {
        RectProjection::RectProjection() : Projection() {}
        RectProjection::RectProjection(float left, float right, float bottom, float top, float zNear, float zFar) : Projection(zNear, zFar), m_left(left), m_right(m_right), m_bottom(bottom), m_top(top) {}
        RectProjection::RectProjection(const RectProjection &from) { *this = from; }
        RectProjection::~RectProjection() {}

        RectProjection &RectProjection::operator=(const RectProjection &from)
        {
            Projection::operator=(from);
            m_left = from.m_left;
            m_right = from.m_right;
            m_bottom = from.m_bottom;
            m_top = from.m_top;
            return *this;
        }

        float RectProjection::get_left() const
        {
            return m_left;
        }

        float RectProjection::get_right() const
        {
            return m_right;
        }

        float RectProjection::get_bottom() const
        {
            return m_bottom;
        }

        float RectProjection::get_top() const
        {
            return m_top;
        }

        void RectProjection::set_left(float left)
        {
            m_left = left;
        }

        void RectProjection::set_right(float right)
        {
            m_right = right;
        }

        void RectProjection::set_bottom(float bottom)
        {
            m_bottom = bottom;
        }

        void RectProjection::set_top(float top)
        {
            m_top = top;
        }
    } // namespace Graphics

} // namespace ntk

#endif