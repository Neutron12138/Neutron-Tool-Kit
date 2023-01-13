#ifndef __NEUTRON_GRAPHICS_TRANSFORM_HPP__
#define __NEUTRON_GRAPHICS_TRANSFORM_HPP__

#include <glm/glm.hpp>
#include "MatrixHolder.hpp"

namespace ntk
{
    namespace Graphics
    {
        class Transform : public MatrixHolder<glm::mat4>
        {
        protected:
            /// @brief 位移
            glm::vec3 m_translation = glm::vec3(0.0f, 0.0f, 0.0f);

            /// @brief 旋转
            glm::vec3 m_rotation = glm::vec3(0.0f, 0.0f, 0.0f);

            /// @brief 缩放
            glm::vec3 m_scale = glm::vec3(1.0f, 1.0f, 1.0f);

        public:
            Transform();
            Transform(const glm::vec3 &translation, const glm::vec3 &rotation, const glm::vec3 &scale);
            Transform(const Transform &from);
            ~Transform();

        public:
            Transform &operator=(const Transform &from);

        public:
            /// @brief 获取位移
            /// @return 位移
            const glm::vec3 &get_translation() const;

            /// @brief 获取旋转
            /// @return 旋转
            const glm::vec3 &get_rotation() const;

            /// @brief 获取缩放
            /// @return 缩放
            const glm::vec3 &get_scale() const;

            /// @brief 设置位移
            /// @param translation 位移
            /// @return 本对象
            virtual void set_translation(const glm::vec3 &translation);

            /// @brief 设置旋转
            /// @param rotation 旋转
            /// @return 本对象
            virtual void set_rotation(const glm::vec3 &rotation);

            /// @brief 设置缩放
            /// @param scale 缩放
            /// @return 本对象
            virtual void set_scale(const glm::vec3 &scale);

        public:
            /// @brief 位移一段距离
            /// @param translation 要位移的距离
            virtual void translate(const glm::vec3 &translation);

            /// @brief 旋转一定角度
            /// @param rotation 要旋转的角度
            virtual void rotate(const glm::vec3 &rotation);

            /// @brief 拉伸一定大小
            /// @param scale 要拉伸的大小
            virtual void scale(const glm::vec3 &scale);

        public:
            virtual void update();
        };
    } // namespace Graphics

} // namespace ntk

#endif