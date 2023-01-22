#ifndef __NEUTRON_GRAPHICS_DRAWINFO_CPP__
#define __NEUTRON_GRAPHICS_DRAWINFO_CPP__

#include "DrawInfo.hpp"

namespace ntk
{
    namespace Graphics
    {
        DrawInfo::DrawInfo(DrawType::DrawType draw_type, PrimitiveType::PrimitiveType primitive_type, GLint first, GLsizei count) : m_draw_type(draw_type), m_primitive_type(primitive_type), m_first(first), m_count(m_count) {}

        DrawType::DrawType DrawInfo::get_draw_type() const
        {
            return m_draw_type;
        }

        PrimitiveType::PrimitiveType DrawInfo::get_primitive_type() const
        {
            return m_primitive_type;
        }

        GLint DrawInfo::get_first() const
        {
            return m_first;
        }

        GLsizei DrawInfo::get_count() const
        {
            return m_count;
        }

        void DrawInfo::set_draw_type(DrawType::DrawType draw_type)
        {
            m_draw_type = draw_type;
        }

        void DrawInfo::set_primitive_type(PrimitiveType::PrimitiveType primitive_type)
        {
            m_primitive_type = primitive_type;
        }

        void DrawInfo::set_first(GLint first)
        {
            m_first = first;
        }

        void DrawInfo::set_count(GLsizei count)
        {
            m_count = count;
        }

        void DrawInfo::draw() const
        {
            switch (m_draw_type)
            {
            case DrawType::DrawType::Arrays:
                glDrawArrays(m_primitive_type, m_first, m_count);
                break;

            case DrawType::DrawType::Elements:
                break;

            default:
                break;
            }
        }
    } // namespace Graphics

} // namespace ntk

#endif