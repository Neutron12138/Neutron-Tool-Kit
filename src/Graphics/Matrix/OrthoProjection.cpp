#ifndef __NEUTRON_GRAPHICS_ORTHOPROJECTION_CPP__
#define __NEUTRON_GRAPHICS_ORTHOPROJECTION_CPP__

#include <glm/gtc/matrix_transform.hpp>
#include "OrthoProjection.hpp"

namespace ntk
{
    namespace Graphics
    {
        OrthoProjection::OrthoProjection() : RectProjection() {}
        OrthoProjection::OrthoProjection(float left, float right, float bottom, float top, float zNear, float zFar) : RectProjection(left, right, bottom, top, zNear, zFar) {}
        OrthoProjection::OrthoProjection(const OrthoProjection &from) { *this = from; }
        OrthoProjection::~OrthoProjection() {}

        OrthoProjection &OrthoProjection::operator=(const OrthoProjection &from)
        {
            RectProjection::operator=(from);
            return *this;
        }

        void OrthoProjection::update()
        {
            m_matrix = glm::ortho(m_left, m_right, m_bottom, m_top, m_zNear, m_zFar);
        }
    } // namespace Graphics

} // namespace ntk

#endif