#ifndef __NEUTRON_GRAPHICS_POLYGONSHAPE_HPP__
#define __NEUTRON_GRAPHICS_POLYGONSHAPE_HPP__

#include "../BaseShape.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 多边形。以GL_TRIANGLE_FAN绘制，框线以GL_TRIANGLE_STRIP绘制
        class PolygonShape : public BaseShape
        {
        protected:
            /// @brief 轮廓宽度
            float m_outline_width = 0.0f;
            /// @brief 轮廓的顶点数据
            VertexData m_outline;

        public:
            PolygonShape();
            PolygonShape(const glm::vec2 &position);
            PolygonShape(const PolygonShape &from);
            ~PolygonShape();

        public:
            PolygonShape &operator=(const PolygonShape &from);

        public:
            /// @brief 获取轮廓填充颜色
            /// @return 轮廓填充颜色
            const glm::vec4 &get_outline_color() const;

            /// @brief 设置轮廓填充颜色
            /// @param outline_color 轮廓填充颜色
            virtual void set_outline_color(const glm::vec4 &outline_color);

            /// @brief 获取轮廓宽度
            /// @return 轮廓宽度
            float get_outline_width() const;

            /// @brief 设置轮廓宽度
            /// @param outline_width 轮廓宽度
            virtual void set_outline_width(float outline_width);

        public:
            virtual void release();

        public:
            virtual void render() = 0;
            virtual void render(UniformBinder &binder, const UniformDescriber &describer) = 0;
            virtual void render_polygon(UniformBinder &binder, const UniformDescriber &describer) = 0;
            virtual void render_outline(UniformBinder &binder, const UniformDescriber &describer) = 0;
        };
    } // namespace Graphics

} // namespace ntk

#endif