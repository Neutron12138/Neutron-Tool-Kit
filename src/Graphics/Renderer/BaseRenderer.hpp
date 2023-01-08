#ifndef __NEUTRON_GRAPHICS_BASERENDERER_HPP__
#define __NEUTRON_GRAPHICS_BASERENDERER_HPP__

#include <glm/glm.hpp>
#include "../../Base/Object.hpp"
#include "../Renderable.hpp"
#include "BaseShape.hpp"
#include "BaseSpatial.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 渲染器的基类
        class BaseRenderer : public Object
        {
        public:
            BaseRenderer();
            BaseRenderer(const BaseRenderer &from);
            ~BaseRenderer();

        public:
            BaseRenderer &operator=(const BaseRenderer &from);

        public:
            /// @brief 开始渲染
            virtual void start_render() = 0;

            /// @brief 设置颜色
            /// @param color 颜色
            virtual void set_color(const glm::vec4 &color) = 0;

            /// @brief 设置点精灵大小
            /// @param size 点精灵大小
            virtual void set_point_size(std::uint32_t size) = 0;

            /// @brief 设置线宽
            /// @param width 线宽
            virtual void set_line_width(std::uint32_t width) = 0;

            /// @brief 绘制点精灵
            /// @param position 点精灵位置
            virtual void draw_point(const glm::vec2 &position) = 0;

            /// @brief 绘制线
            /// @param p1 端点1
            /// @param p2 端点2
            virtual void draw_line(const glm::vec2 &p1, const glm::vec2 &p2) = 0;

            /// @brief 渲染一个可渲染对象
            /// @param shape 要渲染的可渲染对象
            virtual void render(Renderable &renderable) = 0;

            /// @brief 渲染一个2D形状
            /// @param shape 要渲染的2D形状
            virtual void render(BaseShape &shape) = 0;

            /// @brief 渲染一个3D形状
            /// @param shape 要渲染的3D形状
            virtual void render(BaseSpatial<> &spatial) = 0;
        };
    } // namespace Graphics

} // namespace ntk

#endif