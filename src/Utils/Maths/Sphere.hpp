#ifndef __NEUTRON_UTILS_SPHERE_HPP__
#define __NEUTRON_UTILS_SPHERE_HPP__

#include <glm/glm.hpp>
#include "../../Base/Object.hpp"

namespace ntk
{
    namespace Utils
    {
        /// @brief 球体
        class Sphere : public Object
        {
        public:
            /// @brief 计算点在直角坐标系上的位置
            /// @param yaw 偏航角
            /// @param pitch 俯仰角
            /// @param distance 与原点的距离
            /// @return 点在直角坐标系上的位置
            static glm::vec3 calc_rcs_position(float yaw, float pitch, float distance = 1.0f);
        };
    } // namespace Utils

} // namespace ntk

#endif