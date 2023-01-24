#ifndef __NEUTRON_GRAPHICS_VIEW_CPP__
#define __NEUTRON_GRAPHICS_VIEW_CPP__

#include <glm/gtc/matrix_transform.hpp>
#include "View.hpp"

namespace ntk
{
    namespace Graphics
    {
        View::View() : MatrixHolder() { update(); }
        View::View(const glm::vec3 &position, const glm::vec3 &target, const glm::vec3 &up) : MatrixHolder(), m_position(position), m_target(target), m_up(up) { update(); }
        View::View(const View &from) { *this = from; }
        View::~View() {}

        View &View::operator=(const View &from)
        {
            MatrixHolder::operator=(from);
            m_position = from.m_position;
            m_target = from.m_target;
            m_up = from.m_up;
            return *this;
        }

        const glm::vec3 &View::get_position() const
        {
            return m_position;
        }

        const glm::vec3 &View::get_target() const
        {
            return m_target;
        }

        const glm::vec3 &View::get_up() const
        {
            return m_up;
        }

        void View::set_position(const glm::vec3 &position)
        {
            m_position = position;
        }

        void View::set_target(const glm::vec3 &target)
        {
            m_target = target;
        }

        void View::set_up(const glm::vec3 &up)
        {
            m_up = up;
        }

        void View::update()
        {
            m_matrix = glm::lookAt(m_position, m_target, m_up);
        }
    } // namespace Graphics

} // namespace ntk

#endif