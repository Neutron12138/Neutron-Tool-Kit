#ifndef __NEUTRON_GRAPHICS_GLYPH_HPP__
#define __NEUTRON_GRAPHICS_GLYPH_HPP__

#include <glm/glm.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H
#include "../../Base/Object.hpp"
#include "../Texture/Texture2D.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 字形类
        class Glyph : public Object
        {
        protected:
            /// @brief 纹理的大小（单位：像素）
            glm::uvec2 m_size = glm::uvec2(0, 0);
            /// @brief 到基准线的距离（单位：像素）
            glm::ivec2 m_bearing = glm::ivec2(0, 0);
            /// @brief 到下一字形的距离（单位：1/64像素）
            glm::ivec2 m_advance = glm::ivec2(0, 0);
            /// @brief 纹理
            Texture2D m_texture;

        public:
            Glyph();
            Glyph(const Glyph &from);
            ~Glyph();

        public:
            Glyph &operator=(const Glyph &from);

        public:
            /// @brief 获取纹理大小
            /// @return 纹理大小
            const glm::uvec2 &get_size() const;

            /// @brief 获取到基准线的距离
            /// @return 到基准线的距离
            const glm::ivec2 &get_bearing() const;

            /// @brief 获取到下一字形的距离
            /// @return 到下一字形的距离
            const glm::ivec2 &get_advance() const;

            /// @brief 获取纹理
            /// @return 纹理
            const Texture2D &get_texture() const;

        public:
            /// @brief 加载字形数据
            /// @param face FT_Face对象
            virtual void load_data(FT_Face face);

            /// @brief 绑定纹理
            virtual void bind_texture();

            /// @brief 释放资源
            virtual void release();
        };
    } // namespace Graphics

} // namespace ntk

#endif