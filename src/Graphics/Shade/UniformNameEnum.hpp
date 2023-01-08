#ifndef __NEUTRON_GRAPHICS_UNIFORMNAMEENUM_HPP__
#define __NEUTRON_GRAPHICS_UNIFORMNAMEENUM_HPP__

namespace ntk
{
    namespace Graphics
    {
        /// @brief uniform名称枚举的命名空间
        namespace UniformNameEnum
        {
            /// @brief uniform名称枚举
            enum UniformName
            {
                /// @brief 模型矩阵
                ModelMatrix = 0,

                /// @brief 视图矩阵
                ViewMatrix,

                /// @brief 投影矩阵
                ProjectionMatrix,

                /// @brief 颜色
                Color,

                /// @brief 视线位置
                ViewPosition,

                /// @brief 纹理采样器0
                TextureSampler0,

                /// @brief 纹理采样器1
                TextureSampler1,

                /// @brief 总计
                Count,
            };
        } // namespace UniformNameEnum

    } // namespace Graphics

} // namespace ntk

#endif