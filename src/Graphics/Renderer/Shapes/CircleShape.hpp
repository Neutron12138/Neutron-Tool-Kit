#ifndef __NEUTRON_GRAPHICS_CIRCLESHAPE_HPP__
#define __NEUTRON_GRAPHICS_CIRCLESHAPE_HPP__

#include "RegularPolygonShape.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 圆形
        class CircleShape : public RegularPolygonShape
        {
        public:
            CircleShape();
            CircleShape(float radius, std::uint32_t sides = 36);
            CircleShape(const CircleShape &from);
            ~CircleShape();

        public:
            CircleShape &operator=(const CircleShape &from);

        public:
            /// @brief 获取圆形半径，与get_regpol_radius()一样
            /// @return 圆形半径
            float get_circle_radius() const;

            /// @brief 设置圆形半径，与set_regpol_radius()一样
            /// @param radius 圆形半径
            virtual void set_circle_radius(float radius);
        };
    } // namespace Graphics

} // namespace ntk

#endif