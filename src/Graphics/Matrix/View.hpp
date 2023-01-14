#ifndef __NEUTRON_GRAPHICS_VIEW_HPP__
#define __NEUTRON_GRAPHICS_VIEW_HPP__

#include <glm/glm.hpp>
#include "MatrixHolder.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 视图基类
        class View : public MatrixHolder<glm::mat4>
        {
        protected:
            /// @brief 视图的位置
            glm::vec3 m_position = glm::vec3(0.0f, 0.0f, 1.0f);

            /// @brief 视图正在观察的目标位置
            glm::vec3 m_target = glm::vec3(0.0f, 0.0f, 0.0f);

            /// @brief 视图的上向量
            glm::vec3 m_up = glm::vec3(0.0f, 1.0f, 0.0f);

        public:
            View();
            View(const glm::vec3 &position, const glm::vec3 &target, const glm::vec3 &up);
            View(const View &from);
            ~View();

        public:
            View &operator=(const View &from);

        public:
            /// @brief 获取视图的位置
            /// @return 视图的位置
            const glm::vec3 &get_position() const;

            /// @brief 获取视图正在观察的目标位置
            /// @return 视图正在观察的目标位置
            const glm::vec3 &get_target() const;

            /// @brief 获取视图的上向量
            /// @return 视图的上向量
            const glm::vec3 &get_up() const;

            /// @brief 设置视图的位置
            /// @param position 视图的位置
            virtual void set_position(const glm::vec3 &position);

            /// @brief 设置视图正在观察的目标位置
            /// @param target 视图正在观察的目标位置
            virtual void set_target(const glm::vec3 &target);

            /// @brief 设置视图的上向量
            /// @param up 视图的上向量
            virtual void set_up(const glm::vec3 &up);

        public:
            virtual void update();
        };
    } // namespace Graphics

} // namespace ntk

#endif