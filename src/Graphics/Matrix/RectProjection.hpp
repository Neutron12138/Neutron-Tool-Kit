#ifndef __NEUTRON_GRAPHICS_RECTPROJECTION_HPP__
#define __NEUTRON_GRAPHICS_RECTPROJECTION_HPP__

#include <glm/glm.hpp>
#include "Projection.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 矩形的投影
        class RectProjection : public Projection
        {
        protected:
            /// @brief 左边距
            float m_left = -1.0f;
            /// @brief 右边距
            float m_right = 1.0f;
            /// @brief 底边距
            float m_bottom = -1.0f;
            /// @brief 上边距
            float m_top = 1.0f;

        public:
            RectProjection();
            RectProjection(float left, float right, float bottom, float top, float zNear, float zFar);
            RectProjection(const RectProjection &from);
            ~RectProjection();

        public:
            RectProjection &operator=(const RectProjection &from);

        public:
            /// @brief 获取投影左边距
            /// @return 投影的左边距
            float get_left() const;

            /// @brief 获取投影右边距
            /// @return 投影的右边距
            float get_right() const;

            /// @brief 获取投影底边距
            /// @return 投影的底边距
            float get_bottom() const;

            /// @brief 获取投影上边距
            /// @return 投影的上边距
            float get_top() const;

            /// @brief 设置投影左边距
            /// @param left 投影左边距
            virtual void set_left(float left);

            /// @brief 设置投影右边距
            /// @param left 投影右边距
            virtual void set_right(float right);

            /// @brief 设置投影底边距
            /// @param left 投影底边距
            virtual void set_bottom(float bottom);

            /// @brief 设置投影上边距
            /// @param left 投影上边距
            virtual void set_top(float top);
        };
    } // namespace Graphics

} // namespace ntk

#endif