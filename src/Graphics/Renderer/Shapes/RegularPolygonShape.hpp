#ifndef __NEUTRON_GRAPHICS_REGULARPOLYGONSHAPE_HPP__
#define __NEUTRON_GRAPHICS_REGULARPOLYGONSHAPE_HPP__

#include "PolygonShape.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 正多边形
        class RegularPolygonShape : public PolygonShape
        {
        protected:
            /// @brief 正多边形边数
            std::uint32_t m_regpol_sides;
            /// @brief 正多边形半径
            float m_regpol_radius;

        public:
            RegularPolygonShape();
            RegularPolygonShape(std::uint32_t sides, float radius);
            RegularPolygonShape(const RegularPolygonShape &from);
            ~RegularPolygonShape();

        public:
            RegularPolygonShape &operator=(const RegularPolygonShape &from);

        public:
            /// @brief 获取正多边形边数
            /// @return 正多边形边数
            std::uint32_t get_regpol_sides() const;

            /// @brief 设置正多边形边数
            /// @param sides 正多边形边数
            virtual void set_regpol_sides(std::uint32_t sides);

            /// @brief 获取正多边形半径
            /// @return 正多边形半径
            float get_regpol_radius() const;

            /// @brief 设置正多边形半径
            /// @param radius 正多边形半径
            virtual void set_regpol_radius(float radius);

        public:
            virtual void generate_shape();
            virtual void update_VAO();
            virtual void render();
            virtual void render(UniformBinder &binder, const UniformDescriber &describer);
            virtual void render_polygon(UniformBinder &binder, const UniformDescriber &describer);
            virtual void render_outline(UniformBinder &binder, const UniformDescriber &describer);
        };
    } // namespace Graphics

} // namespace ntk

#endif