#ifndef __NEUTRON_GRAPHICS_ORTHOPROJECTION_HPP__
#define __NEUTRON_GRAPHICS_ORTHOPROJECTION_HPP__

#include <glm/glm.hpp>
#include "RectProjection.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 正交投影
        class OrthoProjection : public RectProjection
        {
        public:
            OrthoProjection();
            OrthoProjection(float left, float right, float bottom, float top, float zNear, float zFar);
            OrthoProjection(const OrthoProjection &from);
            ~OrthoProjection();

        public:
            OrthoProjection &operator=(const OrthoProjection &from);

        public:
            virtual void update();
        };
    } // namespace Graphics

} // namespace ntk

#endif