#ifndef __NEUTRON_GRAPHICS_VERTEXATTRIBUTEENUM_HPP__
#define __NEUTRON_GRAPHICS_VERTEXATTRIBUTEENUM_HPP__

#include "../GL.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 顶点属性索引命名空间
        namespace VertexAttributeEnum
        {
            /// @brief 默认顶点属性位置，同时也是VertexAttribDescriber的索引
            enum VertexAttributeLocation
            {
                /// @brief 位置
                Position = 0,

                /// @brief 法线
                Normal,

                /// @brief 纹理坐标
                TexCoord,

                /// @brief 颜色
                Color,

                /// @brief 枚举总数
                LocationCount,
            };
        } // namespace VertexAttributeEnum

    } // namespace Graphics

} // namespace ntk

#endif