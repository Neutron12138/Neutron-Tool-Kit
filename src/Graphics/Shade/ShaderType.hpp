#ifndef __NEUTRON_GRAPHICS_SHADERTYPE_HPP__
#define __NEUTRON_GRAPHICS_SHADERTYPE_HPP__

#include "../GL.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 着色器类型的命名空间
        namespace ShaderType
        {
            /// @brief 着色器类型
            enum ShaderType
            {
                /// @brief 顶点着色器
                Vertex = GL_VERTEX_SHADER,

                /// @brief 片段着色器
                Fragment = GL_FRAGMENT_SHADER,

                /// @brief 几何着色器（需要OpenGL3.2+）
                Geometry = GL_GEOMETRY_SHADER,

                /// @brief 细分控制着色器（需要OpenGL4.0+）
                TessellationControl = GL_TESS_CONTROL_SHADER,

                /// @brief 细分计算着色器（需要OpenGL4.0+）
                TessellationEvaluation = GL_TESS_EVALUATION_SHADER,

                /// @brief 计算着色器（需要OpenGL4.3+）
                Compute = GL_COMPUTE_SHADER,

                /// @brief 总数
                Count = 6,
            };
        } // namespace ShaderType

    } // namespace Graphics

} // namespace ntk

#endif