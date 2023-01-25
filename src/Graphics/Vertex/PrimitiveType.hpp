#ifndef __NEUTRON_GRAPHICS_PRIMITIVETYPE_HPP__
#define __NEUTRON_GRAPHICS_PRIMITIVETYPE_HPP__

#include "../GL.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 图元类型的命名空间
        namespace PrimitiveType
        {
            /// @brief 图元类型
            enum PrimitiveType
            {
                /// @brief 点
                Points = GL_POINTS,

                /// @brief 线条
                Lines = GL_LINES,

                /// @brief 循环线
                LineLoop = GL_LINE_LOOP,

                /// @brief 线条带
                LineStrip = GL_LINE_STRIP,

                /// @brief 三角形
                Triangles = GL_TRIANGLES,

                /// @brief 三角扇形
                TriangleFan = GL_TRIANGLE_FAN,

                /// @brief 三角条带
                TriangleStrip = GL_TRIANGLE_STRIP,

                /// @brief 图元总数
                Count,
            };
        } // namespace PrimitiveType

    } // namespace Graphics

} // namespace ntk

#endif