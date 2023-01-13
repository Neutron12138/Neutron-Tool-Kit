#ifndef __NEUTRON_GRAPHICS_FRUSTUMPROJECTION_CPP__
#define __NEUTRON_GRAPHICS_FRUSTUMPROJECTION_CPP__

#include <glm/gtc/matrix_transform.hpp>
#include "FrustumProjection.hpp"

namespace ntk
{
    namespace Graphics
    {
        FrustumProjection::FrustumProjection() : RectProjection() {}
        FrustumProjection::FrustumProjection(float left, float right, float bottom, float top, float zNear, float zFar) : RectProjection(left, right, bottom, top, zNear, zFar) {}
        FrustumProjection::FrustumProjection(const FrustumProjection &from) { *this = from; }
        FrustumProjection::~FrustumProjection() {}

        FrustumProjection &FrustumProjection::operator=(const FrustumProjection &from)
        {
            RectProjection::operator=(from);
            return *this;
        }

        void FrustumProjection::update()
        {
            m_matrix = glm::frustum(m_left, m_right, m_bottom, m_top, m_zNear, m_zFar);
        }
    } // namespace Graphics

} // namespace ntk

#endif