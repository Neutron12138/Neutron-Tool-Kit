#ifndef __NEUTRON_GRAPHICS_TRANSFORM2D_HPP__
#define __NEUTRON_GRAPHICS_TRANSFORM2D_HPP__

#include <glm/glm.hpp>
#include "MatrixHolder.hpp"

namespace ntk
{
    namespace Graphics
    {
        class Transform2D : public MatrixHolder<glm::mat4>
        {
        protected:
            /// @brief 位移
            glm::vec2 m_translation = glm::vec2(0.0f, 0.0f);

            /// @brief 旋转
            float m_rotation = 0.0f;

            /// @brief 缩放
            glm::vec2 m_scale = glm::vec2(1.0f, 1.0f);

        public:
            Transform2D();
            Transform2D(const glm::vec2 &translation, float rotation, const glm::vec2 scale);
            Transform2D(const Transform2D &from);
            ~Transform2D();

        public:
            Transform2D &operator=(const Transform2D &from);

        public:
            /// @brief 获取位移
            /// @return 位移
            const glm::vec2 &get_translation() const;

            /// @brief 获取旋转
            /// @return 旋转
            float get_rotation() const;

            /// @brief 获取缩放
            /// @return 缩放
            const glm::vec2 &get_scale() const;

            /// @brief 设置位移
            /// @param translation 位移
            virtual void set_translation(const glm::vec2 &translation);

            /// @brief 设置旋转
            /// @param rotation 旋转
            virtual void set_rotation(float rotation);

            /// @brief 设置缩放
            /// @param scale 缩放
            virtual void set_scale(const glm::vec2 &scale);

        public:
            /// @brief 位移一段距离
            /// @param translation 要位移的距离
            virtual void translate(const glm::vec2 &translation);

            /// @brief 旋转一定角度
            /// @param rotation 要旋转的角度
            virtual void rotate(float rotation);

            /// @brief 拉伸一定大小
            /// @param scale 要拉伸的大小
            virtual void scale(const glm::vec2 &scale);

        public:
            virtual void update();
        };
    } // namespace Graphics

} // namespace ntk

#endif