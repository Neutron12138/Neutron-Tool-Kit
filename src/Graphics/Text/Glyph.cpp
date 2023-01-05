#ifndef __NEUTRON_GRAPHICS_GLYPH_CPP__
#define __NEUTRON_GRAPHICS_GLYPH_CPP__

#include "Glyph.hpp"
#include <stb/stb_image_write.h>

namespace ntk
{
    namespace Graphics
    {
        Glyph::Glyph() {}
        Glyph::Glyph(const Glyph &from) { *this = from; }
        Glyph::~Glyph() {}

        Glyph &Glyph::operator=(const Glyph &from)
        {
            m_size = from.m_size;
            m_bearing = from.m_bearing;
            m_advance = from.m_advance;
            m_texture = from.m_texture;
            return *this;
        }

        const glm::uvec2 &Glyph::get_size() const
        {
            return m_size;
        }

        const glm::ivec2 &Glyph::get_bearing() const
        {
            return m_bearing;
        }

        const glm::ivec2 &Glyph::get_advance() const
        {
            return m_advance;
        }

        const Texture2D &Glyph::get_texture() const
        {
            return m_texture;
        }

        void Glyph::load_data(FT_Face face)
        {
            // 初始化纹理
            m_texture.generate();
            m_texture.bind();
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            glGenerateMipmap(GL_TEXTURE_2D);
            m_texture.unbind();

            // 设置参数
            m_size = glm::uvec2(face->glyph->bitmap.width, face->glyph->bitmap.rows);
            m_bearing = glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top);
            m_advance = glm::ivec2(face->glyph->advance.x, face->glyph->advance.y);
        }

        void Glyph::bind_texture()
        {
            m_texture.bind();
        }

        void Glyph::release()
        {
            m_size = glm::uvec2(0, 0);
            m_bearing = glm::ivec2(0, 0);
            m_advance = glm::ivec2(0, 0);
            m_texture.delete_object();
        }
    } // namespace Graphics

} // namespace ntk

#endif