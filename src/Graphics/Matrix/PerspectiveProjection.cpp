#ifndef __NEUTRON_GRAPHICS_PERSPECTIVEPROJECTION_CPP__
#define __NEUTRON_GRAPHICS_PERSPECTIVEPROJECTION_CPP__

#include <glm/gtc/matrix_transform.hpp>
#include "PerspectiveProjection.hpp"

namespace ntk
{
    namespace Graphics
    {
        PerspectiveProjection::PerspectiveProjection() : Projection() { update(); }
        PerspectiveProjection::PerspectiveProjection(float fovy, float aspect, float zNear, float zFar) : Projection(zNear, zFar), m_fovy(fovy), m_aspect(aspect) { update(); }
        PerspectiveProjection::PerspectiveProjection(const PerspectiveProjection &from) { *this = from; }
        PerspectiveProjection::~PerspectiveProjection() {}

        PerspectiveProjection &PerspectiveProjection::operator=(const PerspectiveProjection &from)
        {
            Projection::operator=(from);
            m_fovy = from.m_fovy;
            m_aspect = from.m_aspect;
            return *this;
        }

        float PerspectiveProjection::get_fovy() const
        {
            return m_fovy;
        }

        float PerspectiveProjection::get_aspect() const
        {
            return m_aspect;
        }

        void PerspectiveProjection::set_fovy(float fovy)
        {
            m_fovy = fovy;
        }

        void PerspectiveProjection::set_aspect(float aspect)
        {
            m_aspect = aspect;
        }

        void PerspectiveProjection::update()
        {
            m_matrix = glm::perspective(m_fovy, m_aspect, m_zNear, m_zFar);
        }
    } // namespace Graphics

} // namespace ntk

#endif