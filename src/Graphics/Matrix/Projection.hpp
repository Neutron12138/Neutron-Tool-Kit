#ifndef __NEUTRON_GRAPHICS_PROJECTION_HPP__
#define __NEUTRON_GRAPHICS_PROJECTION_HPP__

// 这里有一个宏叫near和far
// 所以近/远平面用zNear和zFar表示
// #include <windows.h>

#include <glm/glm.hpp>
#include "MatrixHolder.hpp"

namespace ntk
{
    namespace Graphics
    {
        class Projection : public MatrixHolder<glm::mat4>
        {
        protected:
            /// @brief 近平面的距离
            float m_zNear = 0.1f;

            /// @brief 远平面的距离
            float m_zFar = 100.0f;

        public:
            Projection();
            Projection(float zNear, float zFar);
            Projection(const Projection &from);
            ~Projection();

        public:
            Projection &operator=(const Projection &from);

        public:
            /// @brief 获取近平面的距离
            /// @return 近平面的距离
            float get_zNear() const;

            /// @brief 获取远平面的距离
            /// @return 远平面的距离
            float get_zFar() const;

            /// @brief 设置近平面的距离
            /// @param zNear 近平面的距离
            virtual void set_zNear(float zNear);

            /// @brief 设置远平面的距离
            /// @param zFar 远平面的距离
            virtual void set_zFar(float zFar);
        };
    } // namespace Graphics

} // namespace ntk

#endif