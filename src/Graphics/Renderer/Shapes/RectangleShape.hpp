#ifndef __NEUTRON_GRAPHICS_RECTANGLESHAPE_HPP__
#define __NEUTRON_GRAPHICS_RECTANGLESHAPE_HPP__

#include <glm/glm.hpp>
#include "../BaseShape.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 矩形形状
        class RectangleShape : public BaseShape
        {
        protected:
            /// @brief 矩形尺寸
            glm::vec2 m_shape_size = glm::vec2(0.0f, 0.0f);

        public:
            RectangleShape();
            RectangleShape(const glm::vec2 &position, const glm::vec2 &size);
            RectangleShape(const RectangleShape &from);
            ~RectangleShape();

        public:
            RectangleShape &operator=(const RectangleShape &from);

        public:
            /// @brief 获取矩形的尺寸
            /// @return 矩形的尺寸
            const glm::vec2 &get_shape_size() const;

            /// @brief 设置矩形的尺寸
            /// @return 矩形的尺寸
            virtual void set_shape_size(const glm::vec2 &size);

        public:
            virtual void generate_shape();
            virtual void update_VAO();
        };
    } // namespace Graphics

} // namespace ntk

#endif