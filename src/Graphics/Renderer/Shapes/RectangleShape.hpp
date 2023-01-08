#ifndef __NEUTRON_GRAPHICS_RECTANGLESHAPE_HPP__
#define __NEUTRON_GRAPHICS_RECTANGLESHAPE_HPP__

#include <glm/glm.hpp>
#include "PolygonShape.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 矩形形状
        class RectangleShape : public PolygonShape
        {
        protected:
            /// @brief 矩形位置
            glm::vec2 m_rect_position = glm::vec2(0.0f, 0.0f);
            /// @brief 矩形尺寸
            glm::vec2 m_rect_size = glm::vec2(0.0f, 0.0f);

        public:
            RectangleShape();
            RectangleShape(const glm::vec2 &position, const glm::vec2 &size);
            RectangleShape(const RectangleShape &from);
            ~RectangleShape();

        public:
            RectangleShape &operator=(const RectangleShape &from);

        public:
            /// @brief 获取矩形的位置
            /// @return 矩形的位置
            const glm::vec2 &get_rect_position() const;

            /// @brief 设置矩形的位置
            /// @param position 矩形的位置
            virtual void set_rect_position(const glm::vec2 &position);

            /// @brief 获取矩形的尺寸
            /// @return 矩形的尺寸
            const glm::vec2 &get_rect_size() const;

            /// @brief 设置矩形的尺寸
            /// @param size 矩形的尺寸
            virtual void set_rect_size(const glm::vec2 &size);

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