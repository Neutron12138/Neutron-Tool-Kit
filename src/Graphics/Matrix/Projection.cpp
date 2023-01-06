#ifndef __NEUTRON_GRAPHICS_PROJECTION_CPP__
#define __NEUTRON_GRAPHICS_PROJECTION_CPP__

#include "Projection.hpp"

namespace ntk
{
    namespace Graphics
    {
        Projection::Projection() : MatrixHolder() {}
        Projection::Projection(float zNear, float zFar) : MatrixHolder(), m_zNear(zNear), m_zFar(zFar) {}
        Projection::Projection(const Projection &from) { *this = from; }
        Projection::~Projection() {}

        Projection &Projection::operator=(const Projection &from)
        {
            MatrixHolder::operator=(from);
            m_zNear = from.m_zNear;
            m_zFar = from.m_zFar;
            return *this;
        }

        float Projection::get_zNear() const
        {
            return m_zNear;
        }

        float Projection::get_zFar() const
        {
            return m_zFar;
        }

        void Projection::set_zNear(float zNear)
        {
            m_zNear = zNear;
        }

        void Projection::set_zFar(float zFar)
        {
            m_zFar = zFar;
        }
    } // namespace Graphics

} // namespace ntk

#endif