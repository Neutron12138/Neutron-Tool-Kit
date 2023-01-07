#ifndef __NEUTRON_GRAPHICS_BASERENDERER_HPP__
#define __NEUTRON_GRAPHICS_BASERENDERER_HPP__

#include <glm/glm.hpp>
#include "../../Base/Object.hpp"
#include "BaseShape.hpp"

namespace ntk
{
    namespace Graphics
    {
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

            /// @brief 绘制矩形
            /// @param start 矩形起始点
            /// @param size 矩形尺寸
            virtual void draw_rect(const glm::vec2 &start, const glm::vec2 &size) = 0;

            /// @brief 绘制文本
            /// @param text 要绘制的文本
            /// @param position 要绘制的位置
            virtual void draw_text(const std::string &text, const glm::vec2 &position) = 0;

            /// @brief 绘制一个形状
            /// @param shape 要绘制的形状
            virtual void draw(BaseShape &shape) = 0;
        };
    } // namespace Graphics

} // namespace ntk

#endif