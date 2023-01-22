#ifndef __NEUTRON_GRAPHICS_FRUSTUMPROJECTION_HPP__
#define __NEUTRON_GRAPHICS_FRUSTUMPROJECTION_HPP__

#include <glm/glm.hpp>
#include "RectProjection.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 透视投影
        class FrustumProjection : public RectProjection
        {
        public:
            FrustumProjection();
            FrustumProjection(float left, float right, float bottom, float top, float zNear, float zFar);
            FrustumProjection(const FrustumProjection &from);
            ~FrustumProjection();

        public:
            FrustumProjection &operator=(const FrustumProjection &from);

        public:
            virtual void update();
        };
    } // namespace Graphics
    
} // namespace ntk


#endif