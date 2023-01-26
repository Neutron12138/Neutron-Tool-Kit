#ifndef __NEUTRON_GRAPHICS_TEXTURE2D_HPP__
#define __NEUTRON_GRAPHICS_TEXTURE2D_HPP__

#include "Texture.hpp"

namespace ntk
{
    namespace Graphics
    {
        class Texture2D : public Texture
        {
        protected:
            /// @brief 纹理宽度
            GLsizei m_width;
            /// @brief 纹理高度
            GLsizei m_height;
            /// @brief 纹理格式
            GLenum m_format;

        public:
            Texture2D();
            Texture2D(const Texture2D &from);
            ~Texture2D();

        public:
            Texture2D &operator=(const Texture2D &from);

        public:
            /// @brief 获取纹理宽度
            /// @return 纹理宽度
            GLsizei get_width() const;

            /// @brief 获取纹理高度
            /// @return 纹理高度
            GLsizei get_height() const;

        public:
            /// @brief 从文件加载纹理
            /// @param filename 文件名
            /// @return 是否加载成功
            bool load_from_file(const std::string &filename);
        };
    } // namespace Graphics

} // namespace ntk

#endif