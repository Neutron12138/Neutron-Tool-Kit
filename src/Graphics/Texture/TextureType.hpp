#ifndef __NEUTRON_GRAPHICS_TEXTURETYPE_HPP__
#define __NEUTRON_GRAPHICS_TEXTURETYPE_HPP__

#include "../GL.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 纹理类型的命名空间
        namespace TextureType
        {
            /// @brief 纹理类型
            enum TextureType
            {
                /// @brief 1D纹理
                Texture_1D = GL_TEXTURE_1D,

                /// @brief 2D纹理
                Texture_2D = GL_TEXTURE_2D,

                /// @brief 3D纹理
                Texture_3D = GL_TEXTURE_3D,

                /// @brief 立方体映射纹理
                Texture_CubeMap = GL_TEXTURE_CUBE_MAP,

                /// @brief 类型总数
                Count,
            };
        } // namespace TextureType

    } // namespace Graphics

} // namespace ntk

#endif